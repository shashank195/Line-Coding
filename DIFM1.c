#include <graphics.h>

void main(){
	int i, n, bits[10];
	int gdriver = DETECT, gmode;
	int xmax, ymax;
	int up = 1;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	setcolor(getmaxcolor());

	xmax = getmaxx();
	ymax = getmaxy();

	line(0, ymax/2, xmax, ymax/2);
	line(0, 0, 0, ymax);

	printf("Enter size: ");
	scanf("%d", &n);

	setlinestyle(DASHED_LINE, 1, 1);

	for(i = 0; i <=n; i++)
		line(i * 50, 0, i * 50, ymax);

	printf("Enter the digital code: ");
	for(i = 0; i<n; i++)
		scanf("%d", &bits[i]);

	lineto(0, ymax/2 - 50);

	setcolor(10);

	setlinestyle(SOLID_LINE, 1, 1);

	for(i = 0; i<n; i++){
		if(bits[i] == 0){
			if(up)
				linerel(0, 100);
			else
				linerel(0, -100);
			up = up ? 0 : 1;
		}
		linerel(25, 0);
		if(up)
			linerel(0, 100);
		else
			linerel(0, -100);
		up = up ? 0 : 1;
		linerel(25, 0);
	}
	
	getch();
	closegraph();
}
