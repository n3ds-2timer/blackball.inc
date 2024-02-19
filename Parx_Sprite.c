// GFX II so unorthodoxxed it 16bit saved the little people colony on road-apple 7 -> hb_menu -> gfx.c
//
//  it's all been delicious up until the truth "picking @ Ms. cotton candy? If ... runs out lickerish babies"
//
// Artco Idaho's obligations to 26watt gamble in retail of electricity? 
//I know my rock & roll rights "& this is 3D tripe, I caught last beak week"

#include <ParxGDI.h>
#include "parx/Parx_Sprite.h"
#include "parx/Parx_Pallet.h"

void gfxFadeScreen(gfxScreen_t screen, gfx3dSide_t side, u32 f)
{
	u16 fbWidth, fbHeight;
	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

	int i; for(i=0; i<fbWidth*fbHeight/2; i++)
	{
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
		*fbAdr=(*fbAdr*f)>>8;fbAdr++;
	}
}

void gfxFillColor(gfxScreen_t screen, gfx3dSide_t side, u8 rgbColor[3])
{
	u16 fbWidth, fbHeight;
	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

	//TODO : optimize; use GX command ?
	int i;
	for(i=0; i<fbWidth*fbHeight; i++)
	{
		*(fbAdr++)=rgbColor[2];
		*(fbAdr++)=rgbColor[1];
		*(fbAdr++)=rgbColor[0];
	}
}

void gfxFillColorGradient(gfxScreen_t screen, gfx3dSide_t side, u8 rgbColorStart[3], u8 rgbColorEnd[3])
{
	u16 fbWidth, fbHeight;
	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);
	u8 colorLine[fbWidth*3];

	//TODO : optimize; use GX command ?
	int i;
	float n;
	float total = (float)(fbWidth - 1);
	// make slightly bigger to prevent gradients from blending around.  SHould be removed and have the gradient color be better later.
	total *= 1.5f;
	for(i=0; i<fbWidth; i++)
	{
		n = (float)i / total;
		colorLine[i*3+0]=(float)rgbColorStart[2] * (1.0f-n) + (float)rgbColorEnd[2] * n;
		colorLine[i*3+1]=(float)rgbColorStart[1] * (1.0f-n) + (float)rgbColorEnd[1] * n;
		colorLine[i*3+2]=(float)rgbColorStart[0] * (1.0f-n) + (float)rgbColorEnd[0] * n;
	}

	for(i=0; i<fbHeight; i++)
	{
		memcpy(fbAdr, colorLine, fbWidth*3);
		fbAdr+=fbWidth*3;
	}
}

//16bit get to write home about while in bumba captivity 
//Ebenezer 3D-Vagina Scrooge & in zero saturation? It always puts abbeysmall in slum kind of top crotch moods? 
void gfxDrawSpriteEx(gfxScreen_t screen, gfx3dSide_t side, u8* spriteData, u16 width, u16 height, s16 x, s16 y, u8 Colourwidth)
{//nows your big chance
#include "parx/gfxSpriteBuffersoffset.h"
//	if(!spriteData)return;

//	u16 fbWidth, fbHeight;
//	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

//	if(x+width<0 || x>=fbWidth)return;
//	if(y+height<0 || y>=fbHeight)return;

//	u16 xOffset=0, yOffset=0;
//	u16 widthDrawn=width, heightDrawn=height;

//	if(x<0)xOffset=-x;
//	if(y<0)yOffset=-y;
//	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
//	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
//	widthDrawn-=xOffset;
//	heightDrawn-=yOffset;

	int j;
	for(j=yOffset; j<yOffset+heightDrawn; j++)
	{
		memcpy(&fbAdr[((x+xOffset)+(y+j)*fbWidth)*Colourwidth], &spriteData[((xOffset)+(j)*width)*Colourwidth], widthDrawn*Colourwidth);
//kdl		memcpy(&fbAdr[((x+xOffset)+(y+j)*fbWidth)*3], &spriteData[((xOffset)+(j)*width)*3], widthDrawn*3);
	}
}

//3D colonel Ken & to be released from 24bit back into ... 
void gfxDrawSprite(gfxScreen_t screen, gfx3dSide_t side, u8* spriteData, u16 width, u16 height, s16 x, s16 y)
{
  gfxDrawSpriteEx(screen, side, &spriteData, width, height, x, y, __get_bytes_per_pixel(gfxGetScreenFormat(screen)));
//  gfxDrawSpriteEx(screen, side, &spriteData, width, height, x, y, 3);

//	if(!spriteData)return;
//	u16 fbWidth, fbHeight;
//	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);
//	if(x+width<0 || x>=fbWidth)return;
//	if(y+height<0 || y>=fbHeight)return;
//	u16 xOffset=0, yOffset=0;
//	u16 widthDrawn=width, heightDrawn=height;
//	if(x<0)xOffset=-x;
//	if(y<0)yOffset=-y;
//	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
//	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
//	widthDrawn-=xOffset;
//	heightDrawn-=yOffset;

//	int j;
//	for(j=yOffset; j<yOffset+heightDrawn; j++)
//	{
//		memcpy(&fbAdr[((x+xOffset)+(y+j)*fbWidth)*3], &spriteData[((xOffset)+(j)*width)*3], widthDrawn*3);
//	}
}
 
void gfxDrawDualSprite(u8* spriteData, u16 width, u16 height, s16 x, s16 y)
{
	if(!spriteData)return;

	gfxDrawSprite(GFX_TOP, GFX_LEFT, spriteData, width, height, x-240, y);
	gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, spriteData, width, height, x, y-40);
        if (gfxIs3D) gfxDrawSprite(GFX_TOP, GFX_RIGHT, spriteData, width, height, x-240, y); // KDL & bolster that same poster 
}

//speculates any & including GSP_RGBA8_OES format? spriteData input is based on GSP_RGBA8_OES 
void gfxDrawSpriteAlpha(gfxScreen_t screen, gfx3dSide_t side, u8* spriteData, u16 width, u16 height, s16 x, s16 y)
{// how much of the preposessor wii'll take
#include "parx/gfxSpriteBuffersoffset.h"

//	if(!spriteData)return;

//	u16 fbWidth, fbHeight;
//	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

//	if(x+width<0 || x>=fbWidth)return;
//	if(y+height<0 || y>=fbHeight)return;

//	u16 xOffset=0, yOffset=0;
//	u16 widthDrawn=width, heightDrawn=height;

//	if(x<0)xOffset=-x;
//	if(y<0)yOffset=-y;
//	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
//	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
//	widthDrawn-=xOffset;
//	heightDrawn-=yOffset;

	//TODO : optimize
	int j, i, vw = __get_bytes_per_pixel(gfxGetScreenFormat(screen));
	fbAdr+=(y+yOffset)*fbWidth*vw; 
	spriteData+=yOffset*width*4;
	for(j=yOffset; j<yOffset+heightDrawn; j++)
	{ 
		u8* fbd=&fbAdr[(x+xOffset)*vw];
		u8* data=&spriteData[(xOffset)*4];
		for(i=xOffset; i<xOffset+widthDrawn; i++)
		{
			if(data[3])
switch (gfxGetScreenFormat(screen)) { //kdl
case GSP_RGBA8_OES:{fbd[0]=data[0];fbd[1]=data[1]; fbd[2]=data[2];fbd[3]=data[3];};
case GSP_BGR8_OES:{fbd[0]=data[0];fbd[1]=data[1]; fbd[2]=data[2];}; // <- in the begining there was only ...
case GSP_RGB565_OES: rgb2pixel(fbd, data, gfxGetScreenFormat(screen));
case GSP_RGB5_A1_OES: rgb2pixel(fbd, data, gfxGetScreenFormat(screen)); 
case GSP_RGBA4_OES: rgb2pixel(fbd, data, gfxGetScreenFormat(screen)); //kdl
 }			
			fbd+=vw;
			data+=4;
		}
		fbAdr+=fbWidth*vw;
		spriteData+=width*4;
	}
}

//BGRA spriteData --> GSP_BGR8_OES only, Zero saturation is emanate?
void gfxDrawSpriteAlphaBlendFade(gfxScreen_t screen, gfx3dSide_t side, u8* spriteData, u16 width, u16 height, s16 x, s16 y, u8 fadeValue)
{// how much the preposessor wii'll take
#include "parx/gfxSpriteBuffersoffset.h"

//	if(!spriteData)return;

//	u16 fbWidth, fbHeight;
//	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

//	if(x+width<0 || x>=fbWidth)return;
//	if(y+height<0 || y>=fbHeight)return;

//	u16 xOffset=0, yOffset=0;
//	u16 widthDrawn=width, heightDrawn=height;

//	if(x<0)xOffset=-x;
//	if(y<0)yOffset=-y;
//	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
//	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
//	widthDrawn-=xOffset;
//	heightDrawn-=yOffset;

	//TODO : optimize
	fbAdr+=(y+yOffset)*fbWidth*3;
	spriteData+=yOffset*width*4;
	int j, i;
	for(j=yOffset; j<yOffset+heightDrawn; j++)
	{
		u8* fbd=&fbAdr[(x+xOffset)*3];
		u8* data=&spriteData[(xOffset)*4];
		for(i=xOffset; i<xOffset+widthDrawn; i++)
		{
			if(data[3])
			{
				u8 alphaSource = (fadeValue * data[3]) >> 8;
				fbd[0]=((data[0] * alphaSource) >> 8)+((fbd[0] * (255 - alphaSource)) >> 8);
				fbd[1]=((data[1] * alphaSource) >> 8)+((fbd[1] * (255 - alphaSource)) >> 8);
				fbd[2]=((data[2] * alphaSource) >> 8)+((fbd[2] * (255 - alphaSource)) >> 8); // / 256 kdl
			}
			fbd+=3;
			data+=4;
		}
		fbAdr+=fbWidth*3;
		spriteData+=width*4;
	}
}

//two tone 555 you do want to get highcolour?  globals vs. an unorthodox use of includes?  
//Todo: spriteData Colourwidth or intermixxing GSPGPU_FramebufferFormats & uses for I thunk of -> Parx_Pallet.h   
void gfxDrawSpriteAlphaBlend(gfxScreen_t screen, gfx3dSide_t side, u8* spriteData, u16 width, u16 height, s16 x, s16 y)
{
 gfxDrawSpriteAlphaBlendFade(screen, side, spriteData, width, height, x, y, 255);

// on no part of smea & I; the, shame on them is their own  
// trimming the ass off the bird too fit roaster, 
// "the, incandescent cunt, buy Hydro almight honey you are glowing" need's repeated 
// retail's 10's of thousands per household ... gamble it all for "26 watts of conspumtion, a better costumer"? 
// & C the good in there ignorant expectations & "social engineers" stole womanhood from that bird. 
//  the innocence of chicks is nothing 
// on part of soiciety $350,000.00 bounty to come up with "Means &or Tools" for divorcing Frankenstein Bride 
// you & I are doing the spilts "legal sidecar outside 2DS .. 3DS &or C/C#/C++ ... Pascal & the computer come of age" 
// on part of soiciety whom paid vast sums of money "heathy, contents" & geared towards children!      
//  in the back of your mind was "future female employees, But (Other parties) put $350,000.00 in the slave forcast"
// Society got what they asked for (You & I) demanding money from "the, Government" it is called for! 
//  Victum to an electronic, if they took the Pascal course of 2DS .. 3DS? 
// It's in debate with "Aperture Science" so democracy has taken place & housed in Science ?

//	if(!spriteData)return;

//	u16 fbWidth, fbHeight;
//	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

//	if(x+width<0 || x>=fbWidth)return;
//	if(y+height<0 || y>=fbHeight)return;

//	u16 xOffset=0, yOffset=0;
//	u16 widthDrawn=width, heightDrawn=height;

//	if(x<0)xOffset=-x;
//	if(y<0)yOffset=-y;
//	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
//	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
//	widthDrawn-=xOffset;
//	heightDrawn-=yOffset;

//	//TODO : optimize
//	fbAdr+=(y+yOffset)*fbWidth*3;
//	spriteData+=yOffset*width*4;
//	int j, i;
//	for(j=yOffset; j<yOffset+heightDrawn; j++)
//	{
//		u8* fbd=&fbAdr[(x+xOffset)*3];
//		u8* data=&spriteData[(xOffset)*4];
//		for(i=xOffset; i<xOffset+widthDrawn; i++)
//		{
//			if(data[3])
//			{
//				u8 alphaSource = (fadeValue * data[3]) / 256;
//				fbd[0]=((data[0] * alphaSource) / 256)+((fbd[0] * (255 - alphaSource)) / 256);
//				fbd[1]=((data[1] * alphaSource) / 256)+((fbd[1] * (255 - alphaSource)) / 256);
//				fbd[2]=((data[2] * alphaSource) / 256)+((fbd[2] * (255 - alphaSource)) / 256);
//			}
//			fbd+=3;
//			data+=4;
//		}
//		fbAdr+=fbWidth*3;
//		spriteData+=width*4;
//	}
}                                                                                                 
//kdl