install.packages("protr") 
library(bio3d) 
library(protr) 
pdb1 <- read.pdb("1BG2") 
s1 <- aa321(pdb1$seqres) 
s1 <- paste(s1, sep="",collapse="") 
library(seqinr) 
s1 <- c2s(s1) 
extractAAC(s1) 
extractAPAAC(s1, props = c("Hydrophobicity", "Hydrophilicity"), lambda = 30, w = 0.05, customprops = NULL)
extractCTDC(s1) 
extractCTDD(s1) 
extractDC(s1) 

help("extractAAC")