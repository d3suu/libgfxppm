#include <stdlib.h> // malloc, free
#include <stdio.h>
#include "gfx.h"


struct gfx_PPMStruct* gfx_PPMSetup(int width, int height, char R, char G, char B)
{
	struct gfx_PPMStruct* ThisStructure = malloc(sizeof(struct gfx_PPMStruct));
	ThisStructure->width = width;
	ThisStructure->height = height;
	ThisStructure->pixelsCount = (long)(width*height*3); // X*Y*RGB
	ThisStructure->pixels = malloc(ThisStructure->pixelsCount);

	// Fill pixels white, becouse PPM crashes without pixels (just in case)
	for(long i = 0; i < ThisStructure->pixelsCount; i+=3){
		ThisStructure->pixels[i+0] = R;
		ThisStructure->pixels[i+1] = G;
		ThisStructure->pixels[i+2] = B;
	}
	return ThisStructure;
}


void gfx_PPMSetPixel(int x, int y, struct gfx_PPMStruct* structure, char R, char G, char B)
{
	long PixelPlace = (x + (y * structure->width)) * 3;
	structure->pixels[PixelPlace + 0] = R;
	structure->pixels[PixelPlace + 1] = G;
	structure->pixels[PixelPlace + 2] = B;
}


struct gfx_PPMPixel* gfx_PPMGetPixel(int x, int y, struct gfx_PPMStruct* structure)
{
	struct gfx_PPMPixel* ThisPixel = malloc(sizeof(struct gfx_PPMPixel));
	long PixelPlace = (x + (y * structure->width)) * 3;
	ThisPixel->R = structure->pixels[PixelPlace + 0];
	ThisPixel->G = structure->pixels[PixelPlace + 1];
	ThisPixel->B = structure->pixels[PixelPlace + 2];
	return ThisPixel;
}


void gfx_PPMExport(struct gfx_PPMStruct* structure, char* filename)
{
	FILE *fp = fopen(filename, "wb");
	fprintf(fp, "P6\n%d %d\n255\n", structure->width, structure->height);
	for(long i = 0; i < structure->pixelsCount; i++){
		fputc(structure->pixels[i], fp);
	}
	fclose(fp);
}


struct gfx_PPMStruct* gfx_PPMImport(char* filename)
{
	FILE *fp = fopen(filename, "rb");
	char buffer[2];
	fgets(buffer, 2, fp); // TODO check if its possible to read
	// if(strcmp(buffer, "P6")) // TODO
}


void gfx_PPMFree(struct gfx_PPMStruct* structure)
{
	free(structure->pixels);
	free(structure);
}
