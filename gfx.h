#ifndef _GFX_PPM_H
#define _GFX_PPM_H


// the image structure
struct gfx_PPMStruct
{
	int width;
	int height;
	long pixelsCount; // width*height*3 (width*height*RGB)
	char* pixels; // char array of pixel (from left to right, up to down)
};


// structure for working with individual pixels
struct gfx_PPMPixel
{
	char R;
	char G;
	char B;
};


// calculate things, alloc memory for pixels, return structure
struct gfx_PPMStruct* gfx_PPMSetup(int width, int height, char R, char G, char B);


// set RGB pixel on XY in structure (object)
void gfx_PPMSetPixel(int x, int y, struct gfx_PPMStruct* structure, char R, char G, char B); 


// get pixel, return RGB value in gfx_PPMPixel struct
struct gfx_PPMPixel* gfx_PPMGetPixel(int x, int y, struct gfx_PPMStruct* structure);
/* USAGE:
 *
 * struct gfx_PPMPixel* MyPixel = gfx_PPMGetPixel(1, 2, MyPPMStructure);
 * printf("R: %x, G: %x, B: %x\n", MyPixel->R, MyPixel->G, MyPixel->B);
 * free(MyPixel);
 *
 */


// export PPM
void gfx_PPMExport(struct gfx_PPMStruct* structure, char* filename);

// TODO -> fix for comments in PPM file (will only work with PPM's without comments)
// import PPM
struct gfx_PPMStruct* gfx_PPMImport(char* filename);


// free structure memory
void gfx_PPMFree(struct gfx_PPMStruct* structure); 


#endif
