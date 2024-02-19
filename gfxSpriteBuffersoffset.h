//fiscal fact: elctricity spent on 3D &or Porno meet obligations we have -> /3ds_hb_menu/source/gfx.c
//too troubled us with slum things, was explained to myriad of genius in code"
//Means well?? "Orifice Annie & Sugar daddy war bucks with Tripe's a crime momma popped you out that way shitstories"
//"I can't look past pulling incisor's out of beavers" & buy the way Warbucks & Midas where is sum of money for us?
// Need get on my 2DS .. 3DS freepascal nerves over it "get rich 26 watts pitting harm"   

	if(!spriteData)return;

	u16 fbWidth, fbHeight;
	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

	if(x+width<0 || x>=fbWidth)return;
	if(y+height<0 || y>=fbHeight)return;

	u16 xOffset=0, yOffset=0;
	u16 widthDrawn=width, heightDrawn=height;

	if(x<0)xOffset=-x;
	if(y<0)yOffset=-y;
	if(x+width>=fbWidth)widthDrawn=fbWidth-x;
	if(y+height>=fbHeight)heightDrawn=fbHeight-y;
	widthDrawn-=xOffset;
	heightDrawn-=yOffset;

//polarized x,y to flip &or invert ?