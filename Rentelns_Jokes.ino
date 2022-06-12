/* SCROLLING LED MESSAGE SIGN FOR THE CSUSB PHYSICS DEPARTMENT STUDY ROOM
   Displays a welcome message, and then a joke from Dr. Paul Renteln
   All jokes taken from ``Foolproof: A Sampling of Mathematical Folk Humor" (with A. Dundes), Notices of the AMS, 52 (2005) 24-34.

   Code written by Austin Everman, based on Parola example sketches

   NEED TO DO:
   - Program crashes after some time, STRING not flushing and overflowing memory?
   -> Use pointers to STRING rather than copy to memory?
*/

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
#define	MAX_DEVICES	4
#define	CLK_PIN		13
#define	DATA_PIN	11
#define	CS_PIN		10

// HARDWARE SPI
MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);

char curMessage[140] = " ";
bool welcome = true;
byte joke = 1;

void setup()
{
  P.begin();
  P.displayClear();
  P.displaySuspend(false);
  P.displayScroll(curMessage, PA_LEFT, PA_SCROLL_LEFT, 60);
}

void loop()
{
  if (P.displayAnimate())
  {
    if (welcome == false)
    {

      if (joke == 1)
      {
        strcpy(curMessage, "Q: What do you call a young eigensheep?   A: A lamb, duh!");
      }
      if (joke == 2)
      {
        strcpy(curMessage, "Q: What's the value of a contour integral around Western Europe?   A: Zero, because all the Poles are in Eastern Europe.");
      }
      if (joke == 3)
      {
        strcpy(curMessage, "Q: What is a topologist?   A: Someone who cannot distinguish between a doughnut and a coffee cup.");
      }
      if (joke == 4)
      {
        strcpy(curMessage, "Q: Why didn't Newton discover group theory?   A: Because he wasn't Abel.");
      }
      if (joke == 5)
      {
        strcpy(curMessage, "Q: What do you get if you cross an elephant and a banana?   A: |elephant|*|banana|*sin(theta).");
      }
      if (joke == 6)
      {
        strcpy(curMessage, "Q: What do you get if you cross a mosquito with a mountain climber?   A: You can't cross a vector with a scalar.");
      }
      if (joke == 7)
      {
        strcpy(curMessage, "Q: What do you get when you cross a mountain goat and a mountain climber?   A: Nothing:you can't cross two scalars");
      }
      if (joke == 8)
      {
        strcpy(curMessage, "Q: What's a dilemma?   A: A lemma that produces two results.");
      }
      if (joke == 9)
      {
        strcpy(curMessage, "Q: What's a polar bear?   A: A rectangular bear after a coordinate transform.");
      }
      if (joke == 10)
      {
        strcpy(curMessage, "Q: What is a proof?   A: One-half percent of alcohol.");
      }
      if (joke == 11)
      {
        strcpy(curMessage, "Q: What does an analytic number theorist say when he is drowning?   A: Log-log, log-log, log-log,...");
      }
      if (joke == 12)
      {
        strcpy(curMessage, "Q: How many topologists does it take to change a lightbulb?   A: Just one, but what will you do with the doughnut?");
      }
      if (joke == 13)
      {
        strcpy(curMessage, "Q: How many geometers does it take to screw in a lightbulb?   A: None. You can't do it with a straightedge and compass.");
      }
      if (joke == 14)
      {
        strcpy(curMessage, "Q: How many mathematicians does it take to screw in a lightbulb?   A: 0.999999...");
      }
      if (joke == 15)
      {
        strcpy(curMessage, "Q: Why did the chicken cross the Moebius strip?   A: To get to the other.. er...");
      }
      if (joke == 16)
      {
        strcpy(curMessage, "Q: Why did the chicken cross the Moebius strip?   A: To get to the same side.");
      }

      joke++;

      if (joke > 16)
      {
        joke = 1;
      }
      welcome = true;
    }
    else
    {
      strcpy(curMessage, "Welcome to the CSUSB Physics Department!");
      welcome = false;
    }
    P.displayReset();
  }
}
