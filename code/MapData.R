# Author: Ulises Olivares
# Date: May 18, 2021
# uolivares@unam.mx

#IMAC path 
setwd("~/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/GBIF")

#Macbook pro path
#setwd("~/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/GBIF")

fileName <-"baccharis2021.csv"
bacc <- read.csv(fileName, sep="\t")

location <- data.frame(bacc$species, bacc$decimalLongitude, bacc$decimalLatitude)

print(paste("Total registers:", nrow(location)))

#Remove registers with NA
cleanLoc <- na.omit(location)
names(cleanLoc) <- c("species", "longitude", "latitude")
print(paste("Registers with location:", nrow(cleanLoc)))

#Free mem
rm(location)
rm(bacc)

#Remove duplicated registers
dups <- duplicated(cleanLoc[c("longitude", "latitude")])
uniqueLoc <- cleanLoc[!dups, ]
cat(nrow(cleanLoc) - nrow(uniqueLoc), "Records are removed")

print(paste("Unique registers:", nrow(uniqueLoc)))

#summary(cleanLoc)


removig near points
occ2thin = poThin(
  df = uniqueLoc,
  spacing = 50, #minimum distance between points in thinned data in kms
  dimension = nrow(uniqueLoc),
  lon = 'longitude',
  lat = 'latitude'
)

uniqueLoc <- uniqueLoc[-occ2thin,] #thin using index returned from occ2thin

print(paste("Registers after thining:", nrow(uniqueLoc)))


# randomly select 10 occurrences
index <- sample(nrow(uniqueLoc),10)

Sp_ind <- uniqueLoc[index,]

Sp_joint <- uniqueLoc[-index, ] # Remove independent random points

# Save unique registers in a CSV file
write.csv(Sp_joint,"Sp_joint.csv")

write.csv(Sp_ind, "Sp_ind.csv")

print(paste("Sp_joint registers:", nrow(Sp_joint)))
print(paste("Sp_ind registers:", nrow(Sp_ind)))


# Load ENMeval and split data in Train and Test.
#install.packages('ENMeval')
#install.packages('caret')
library(ENMeval)
library(dismo)

# Generate random points over an extent
bg <- dismo::randomPoints(bioVars[[1]], n = nrow(Sp_joint))

jack <- get.jackknife(occs = uniqueLoc, bg)

random <- get.randomkfold(occs = uniqueLoc, bg = bg, kfolds = 4)


setwd("/Users/ulises/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/GBIF")

# Subset data in train and test
test <- which(random$occs.grp == 1)                                                # 25% for testing 
train <- which(random$occs.grp == 2 | random$occs.grp == 3 | random$occs.grp == 4) # 75% for training

testCSV <- Sp_joint[test,]
trainCSV <- Sp_joint[train,]

write.csv(testCSV, "Sp_test.csv")
write.csv(trainCSV, "Sp_train.csv")


# ---------------------------------
# 2. Thin input data --------------
# ---------------------------------
#install.packages(c("rasterExtras", "r-spatial", "spocc"))
library(devtools)
#devtools::install_github("rspatial/rspatial", force=TRUE)

#install.packages("rasterextras")
#install.packages("occ2")
#devtools::install_github("rsh249/rasterExtras")
#devtools::install_github('oshea-patrick/RSpatial')
#install.packages("dismo")
#install.packages("occ")

library(raster)
library(ggplot2)
library(rasterExtras)
#library(spocc)
#library(occ)
library(dplyr)
library(RSpatial)
library(dismo)
library(gtools)

# Add +-1  to ensure all points are inside bounding box

bb <- extent(min(uniqueLoc$longitude) , max(uniqueLoc$longitude), min(uniqueLoc$latitude), max(uniqueLoc$latitude))

# 1 degree = 16 miles
ext <- extent(min(uniqueLoc$longitude), max(uniqueLoc$longitude), min(uniqueLoc$latitude), max(uniqueLoc$latitude))

setwd("/Volumes/DATALacie/worldclim/wc2.1_30s_bio/")

## Import worldclim data
# Read all rasters from worldclim
rastlist <- list.files(path = "/Volumes/DATALacie/worldclim/wc2.1_30s_bio/", pattern='.tif$', all.files=TRUE, full.names=FALSE)
rastlist <- mixedsort(rastlist)

# Stack all rasters
bio <- stack(rastlist)

# Crop rasters
bioVars <- crop(bio, ext)

# Free memory
#rm(bio)

# Transform to dataframe
bioVars_df <- as.data.frame(bioVars, xy=TRUE)# for ploting

names(bioVars_df) <- c("x", "y", "bio1", "bio2", "bio3", "bio4", "bio5", "bio6", "bio7", "bio8", "bio9", "bio10", 
                 "bio11", "bio12", "bio13", "bio14", "bio15", "bio16", "bio17", "bio18", "bio19")



#plot
#ggplot() +
#  geom_raster(data = bioVars_df, aes(x = x, y = y, fill = bio1)) +
#  geom_point(data=sp_df, aes(x=longitude, y=latitude), col='green', cex=0.1) +
#  coord_quickmap() +
#  theme_bw() + 
#  scale_fill_gradientn(colours=c('darkred', 'grey', 'navy', 'green'),
#                       na.value = "black")


# Execute this once
# -----------------------------
# 3. Export files to .asc files 
# -----------------------------
#setwd("/Volumes/DATA Lacie/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/b_drancunculifolia")

relevantBio <- c("bio1", "bio2", "bio3", "bio4", "bio5", "bio6", "bio7", "bio8", "bio9", "bio10", 
  "bio11", "bio12", "bio13", "bio14", "bio15", "bio16", "bio17", "bio18", "bio19")

indices <- list(4)

#Export all current variables in an .asc format without cropping (full dataset, different format)
for(i in indices){
  print(paste("bio",i))
  current <- bio[[i]]
  writeRaster(current, paste(names(bioVars_df[i+2]),"_full"), format = "ascii", overwrite=TRUE)
}

# Export all files as .asc
#for(i in 1:nlayers(bioVars)){
#  print(names(bioVars_df[i+2]))
#  current <- bioVars[[i]]
#  writeRaster(current, names(bioVars_df[i+2]), format="ascii", overwrite=TRUE)
#}

# -------------------------------------------------
# 4. Getting new layers: Elevation, aspect and slope
# -------------------------------------------------

### Elevation

# IMAC
setwd("/Volumes/DATALacie/worldclim/elevation")
rastlist <- list.files(path = "/Volumes/DATALacie/worldclim/elevation", pattern='.tif$', all.files=TRUE, full.names=FALSE)

# Macbook Pro
#setwd("//Users/uolivares/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/elevation")
#rastlist <- list.files(path = "/Users/uolivares/OneDrive - UNAM/0. UNAM - Juriquilla/4. COLABORACIONES/6. Geraldo/3. Data/elevation", pattern='.tif$', all.files=TRUE, full.names=FALSE)

dem <- raster(rastlist)
# Crop raster to interest area
dem <- crop(dem, ext)
dem_df<- as.data.frame(dem)
names(dem_df) <- c("elevation")
# Export dem raster in ascii format
#writeRaster(dem, "dem", format = "ascii", overwrite=TRUE)

### Calculate slope and aspect from elevation



# Calculate and export slope
slope <-  terrain(dem, opt= 'slope', unit='tangent', neighbors=8)
slope_df <- as.data.frame(slope)
names(slope_df) <- c("slope")
#writeRaster(slope, "slope", format = "ascii", overwrite=TRUE)

# Calculate and export aspect
aspect <- terrain(dem, opt='aspect', unit='degrees', neighbors=8)
aspect_df <- as.data.frame(aspect)
names(aspect_df) <- c("aspect")
#writeRaster(aspect, "aspect", format = "ascii", overwrite=TRUE)

# Joint all variables
bioVars_df$dem <- dem_df
bioVars_df$slope <- slope_df
bioVars_df$aspect <- aspect_df


names(bioVars_df) <- (c("x", "y", "bio1", "bio2", "bio3", "bio4", "bio5", "bio6", "bio7", "bio8", "bio9", "bio10", 
                  "bio11", "bio12", "bio13", "bio14", "bio15", "bio16", "bio17", "bio18", "bio19", 
                  "elevation", "slope", "aspect"))

# TODO: change names of dataframe to make a better repesentation

# ------------------------------------------------------------------
# 5. Correlation of environmental variables, dem, slope and aspect
# ------------------------------------------------------------------
#install.packages("ggpubr")
#install.packages("Hmisc")
#install.packages("ggcorrplot")
#install.packages("caret")
#install.packages("IDPmisc") # remove NA nad NaN
library(Hmisc)
library(ggpubr)
library(corrplot)
library(IDPmisc)
library(RColorBrewer)
library(ggcorrplot)
library(caret)

# Drop all rows with NA
allVars <- na.omit(bioVars_df[3:24])

#Drop all rows with NA, NaN -inf, inf, etc.
allVars <- NaRV.omit(allVars)

# Calculate pearson correlation
correlation <- cor(allVars, method = c("pearson"))


# Select highly correlated variables 
cutoff <- findCorrelation(correlation, cutoff = 0.8, verbose = TRUE, exact=TRUE, names = TRUE)

finalVars<- sort(cutoff)

finalbioclimCut<- allVars[finalVars]

print(finalVars)

ext
# Generate plot
#corrplot(correlation, order = "hclust", hclust.method = "average", insig="p-value", sig.level = -1, addrect = 10, tl.cex = 0.7, tl.col = "black", method = "color", type="upper")

#corrplot.mixed(correlation, order = "hclust", hclust.method = "average", upper = "color", lower = "number", tl.pos = "lt")

corPlot <- ggcorrplot(correlation, hc.order=TRUE, lab=TRUE, type = "upper", color = c("#FC4E07", "white", "#00AFBB"))

ggsave(corPlot, filename = "correlation", device = "tiff", dpi = 600, width = 9, height = 9)

library(tiff)
tiff(file = "heatmap", units="in", width=16, height=9, res=600)

# TODO: Generate a heat map with dendogram
heatmap(correlation, symm=TRUE, col= colorRampPalette(brewer.pal(8, "Blues"))(25))

dev.off()


#install.packages("heatmaply")
library(heatmaply)



2tiff(file = "heatmap2", units="in", width=9, height=9, res=600)

#rcorrelation <- rcorr(allVars)
heatmaply_cor(
  correlation,
  #xlab = "Variables", 
  #ylab = "Variables",
  k_col = 5, 
  k_row = 5
)

dev.off()




#TODO: Change this to a heatmap 
# -------------------------------------
# --- 6. Generate a map of original data---
# -------------------------------------
#devtools::install_github("ropensci/plotly")
"""library(plotly)
fig <- quakes 
fig <- fig %>%
  plot_ly(
    type = 'densitymapbox',
    lat = ~sp_df$latitude,
    lon = ~sp_df$longitude,
    coloraxis = 'coloraxis',
    radius = 4) 
fig <- fig %>%
  layout(
    mapbox = list(
      style='stamen-terrain',
      center= list(lat=-20.928, lon=-56.70), zoom=3.5), coloraxis = list(colorscale = 'Viridis'))

fig <- fig %>%
  config(toImageButtonOptions = list(format = 'jpeg'))

fileName <- 'baccaris.jpeg'
dpi <- 300
orca(fig, file = fileName, width=3 * dpi, height = 3 * dpi, scale = 18, parallel_limit = 4, verbose = 2, timeout=100000) %>%
  config(toImageButtonOptions = list(format = 'svg'))
fig"""

######################################################################################
# Process individual records downloaded from I-naturalist to validate selected models
setwd("/Volumes/DATALacie/baccharis")

#Import and clean data
ind <- read.csv("Sp_ind.csv")

print(paste("Original registers: ", nrow(ind)))

# Cleaning and thining data

#Remove duplicated registers
dupsInd <- duplicated(ind[c("longitude", "latitude")])
uniqueInd <- ind[!dupsInd, ]
cat(nrow(ind) - nrow(uniqueInd), "records were removed")

print(paste("Unique registers:", nrow(uniqueInd)))

#removig near points
occ2thin = poThin(
  df = uniqueLoc,
  spacing = 50, #minimum distance between points in thinned data in kms
  dimension = nrow(uniqueLoc),
  lon = 'longitude',
  lat = 'latitude'
)


uniqueInd <- uniqueInd[-occ2thin,] #thin using index returned from occ2thin

print(paste("Registers after thining:", nrow(uniqueInd)))


