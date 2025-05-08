
#include<stdio.h> 
#include<graphics.h> 
#include<conio.h> 
#include<stdlib.h> 
#include <winbgim.h> 

void playButton(int x, int y, int width, int height, char *label) { 

  setcolor(WHITE); 
  rectangle(x, y, x + width, y + height);
  setfillstyle(SOLID_FILL, BLACK);

  setcolor(WHITE); // Set the text color to WHITE
  setbkcolor(BLACK); // Set the background color for the text to BLACK
  outtextxy(x + width / 4 , y + height / 4, label);
}


void countm(int *co_mo,int* inc){

  *inc+=5; // Increase the increment value by 5 to animate arcs dynamically

  // Draw two concentric arcs with decreasing angles as inc increases (creates a rotating effect)
  setcolor(DARKGRAY);  // Set color for the first set of arcs
  arc(530,150,340-(*inc),80-(*inc),50);
  arc(530,150,340-(*inc),80-(*inc),51);

  // Draw another set of arcs in the opposite direction for visual complexity
  setcolor(DARKGRAY);
  arc(530,150,100+(*inc),200+(*inc),55);
  arc(530,150,100+(*inc),200+(*inc),56);

  // Draw a third arc with a different color 
  setcolor(DARKGRAY);
  arc(530,150,220-(*inc),320+(*inc),60);

  setcolor(YELLOW);
  outtextxy(515,198,"MOVE");

  // Convert the current move count to a string and display it
  char arr[50];
  sprintf(arr,"%d",*co_mo);

  setcolor(CYAN);
  outtextxy(520,165,arr);

  // Increment the move counter
  *co_mo=*co_mo+1;

  setcolor(RED);
  outtextxy(500,240,"w -> Up");
  outtextxy(500,260,"s -> Down");
  outtextxy(500,280,"a -> Left");
  outtextxy(500,300,"d -> Right");
}

void body() {

  setcolor(GREEN);

  //horizontal line
  setcolor(3);  
  line(0,100,450,100); 
  line(50,130,400,130);
  line(100,160,450,160);
  line(150,190,300,190);
  line(100,220,250,220);
  line(50,250,200,250);
  line(0,400,500,400);
  line(450,370,500,370);

  //vertical line
  line(0,100,0,400); 
  line(50,130,50,370);
  line(100,160,100,220);
  line(100,280,100,400);
  line(150,250,150,370);
  line(200,280,200,400);
  line(250,220,250,370);
  line(300,190,300,400);
  line(350,160,350,370);
  line(400,190,400,400);
  line(450,100,450,370);

  setcolor(WHITE);
  circle(500,385,10);
}

void ball(int j,int k,int l) {
 circle(j,k,l);
 setcolor(WHITE);

 setfillstyle(SOLID_FILL,YELLOW); 
 // Fill the inside of the circle with yellow color, starting from the center point (j, k)
 // It will fill until it reaches a boundary of color WHITE (the circle border)
 floodfill(j,k,WHITE);
}

void condition(int *j,int *k){  

  // If the object is on y = 110 and within x-range (0 < x < 450), allow downward movement (+5 in y)
  if(*k==110){
	   if(*j<450 && *j>0)
	   *k=*k+5;
	   }

  // If the object is on x = 10 and within y-range (100 < y < 400), allow rightward movement (+5 in x)
   if(*j==10){
    if(*k<400 && *k>100)
	*j+=5;
   }

  // If the object is on y = 390 and within x-range (0 < x < 500), allow upward movement (-5 in y)
   if(*k==390){
     if(*j<500 &&* j>0)
     *k-=5;
     }

  // If the object is on x = 440 and within y-range (100 < y < 380), allow leftward movement (-5 in x)
   if(*j==440){
     if(*k>100 && *k<380)
     *j-=5;
     }
   if(*k==380){
   if(*j<500&& *j>440)
   *k+=5;
   }

   if(*k>=120 && *k<=140 ){
   if(*j<410 && *j>40 && *k<=130)
   *k-=5;
   if(*j<410 && *j>40 && *k>=130)
   *k+=5;
   }
  if(*k>=150 && *k<=170 && *j>=90 &&* j<=450){
  if(*k<=160) *k-=10;
  *k+=5;
  }
  if(*k>=180&&*k<=200&&*j>=140&&*j<=310)
  { if(*k>=190 ) *k+=10;
    *k-=5;}
  if(*k>=210&&*k<=230&&*j>=90&&*j<=260)
  {if(*k>=220) *k+=10;
   *k-=5;
  }
  if(*k<=260 && *k>=240 && *j<=210&& *j>40){
  if(*k>=250) *k+=10;
  *k-=5;
  }
  if(*k<=370&&*k>=130&&*j<=60&&*j>=40){
  if(*j<=50) *j-=10;
  *j+=5;
  }
  if(*k<=220&&*k>=160&&*j<=110&&*j>=90){
  if(*j<=100) *j-=10;
  *j+=5;
  }
  if(*k<=400&&*k>=280&&*j<=110&&*j>=90){
  if(*j<=100) *j-=10;
  *j+=5;
  }
  if(*k<=370&&*k>=250&&*j<=160&&*j>=140){
  if(*j<=150) *j-=10;
  *j+=5;
  }
  if(*k<=400&&*k>=280&&*j<=210&&*j>=190){
  if(*j<=200) *j-=10;
  *j+=5;
  }
  if(*k<=370&&*k>=220&&*j<=260&&*j>=240){
  if(*j<=250) *j-=10;
  *j+=5;
  }
  if(*k<=400&&*k>=190&&*j<=310&&*j>=290){
  if(*j<=300) *j-=10;
  *j+=5;
  }
  if(*k<=370&&*k>=160&&*j<=360&&*j>=340){
  if(*j<=350) *j-=10;
  *j+=5;
  }
  if(*k<=400&&*k>=190&&*j<=410&&*j>=390){
  if(*j<=400) *j-=10;
  *j+=5;
  }
}

void caption()
{
  setcolor(LIGHTRED);
  settextstyle(0,HORIZ_DIR,0);
  outtextxy(10,20,"Escape from the Maze");
  outtextxy(10,40,"or Press 'SPACE' to EXIT");
}


void drawConfetti() {

  // Get the center of the screen (X and Y coordinates)
  int midX = getmaxx() / 2;
  int midY = getmaxy() / 2;

  const int numConfetti = 50;   // Number of confetti pieces
  // Arrays to store confetti properties: position (x, y), movement (dx, dy), and color
  int x[numConfetti], y[numConfetti], dx[numConfetti], dy[numConfetti], color[numConfetti];

    // Initialize each confetti piece with random position, movement, and color
  for (int i = 0; i < numConfetti; i++) {
      x[i] = rand() % getmaxx();
      y[i] = rand() % getmaxy();
      dx[i] = -2 + rand() % 5;  
      dy[i] = 1 + rand() % 3;   
      color[i] = 1 + rand() % 15;
  }

  // Animation loop: runs for 100 frames
  for (int frame = 0; frame < 100; frame++) {
      cleardevice(); // Clear the screen before drawing the next frame

  // Draw the "You Won" message at the center of the screen
      settextstyle(1, HORIZ_DIR, 4);
      setcolor(YELLOW);
      outtextxy(midX - textwidth("You Won") / 2, midY - textheight("You Won") / 2, "You Won");
  
  // Draw and move each piece of confetti
      for (int i = 0; i < numConfetti; i++) {
          setcolor(color[i]);
          line(x[i], y[i], x[i] + 15, y[i] + 15); // Draw diagonal line representing the confetti
          x[i] += dx[i]; // Update X position
          y[i] += dy[i]; // Update Y position

    // If the confetti goes off the bottom of the screen, reset it to the top with new properties
          if (y[i] > getmaxy()) {
              x[i] = rand() % getmaxx();
              y[i] = 0;
              dx[i] = -2 + rand() % 5;
              dy[i] = 1 + rand() % 3;
              color[i] = 1 + rand() % 15;
          }
      }

      delay(50);  // Pause briefly before the next frame to control animation speed
  }
}

int level_1(int *p)
{
 int i,j=20,k=250,l=10,m=10 ; // j and k are ball coordinates, l is radius, m is a loop counter
 int co_mo=0,inc=0; // co_mo: move count, inc: helper for move counting
 int mouseX, mouseY; // Mouse coordinates
 char c;
 cleardevice();

 // Display the start menu
 while(1){
 setcolor(MAGENTA);
 settextstyle(1,HORIZ_DIR,6);
 outtextxy(getmaxx()/2 - textwidth("Maze Game")/2, 150,"Maze Game");
 
 settextstyle(0,HORIZ_DIR,0);
playButton(getmaxx() / 2 - 50, 300, 100, 40, "Play");

// Wait for mouse click
 while (!ismouseclick(WM_LBUTTONDOWN)) {
  delay(100); // Check every 100ms
  }
  getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY); // Get click coordinates
  
  // If the click was inside the "Play" button area, break the loop
  if (mouseX >= getmaxx() / 2 - 50 && mouseX <= getmaxx() / 2 + 50 &&
  mouseY >= 300 && mouseY <= 340) {
  break;
  }

 getch();
  }
 cleardevice();

 body();          
 ball(j,k,l);     
 caption();
 countm(&co_mo,&inc);

for(i=0;i<m++;i++){
 condition(&j,&k); //cheacking condition
 countm(&co_mo,&inc); // Update move counter
 c=getch(); // Get user input (arrow keys or wasd)
 cleardevice(); // Clear screen to redraw everything

 if(c==75||c=='a') j-=5;
 if(c==80||c=='s') k+=5;
 if(c==77||c=='d') j+=5;
 if(c==72||c=='w') k-=5;
 if(c==' ') return 0;

*p=co_mo; // Store current move count in the pointer variable passed to function

// Redraw updated game state
 caption();
 body();        
 ball(j,k,l);   

// If ball reaches goal 
 if(j >= 500) {
  cleardevice(); // Clear screen
  drawConfetti(); // Show win animation
  getch(); // Wait for a key press
  return 1;
}

  }
}


int main()
{
  int gd=DETECT,gm;
  int flag,point=0;
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  flag=level_1(&point);

getch();
closegraph();
}