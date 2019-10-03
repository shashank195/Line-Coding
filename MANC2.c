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
		if(bits[i] == up)
			linerel(0, -100 + 200 * bits[i]);
		up = bits[i];
		linerel(25, 0);
		linerel(0, 100 - 200 * bits[i]);
		linerel(25, 0);
	}
	
	getch();
	closegraph();
}
