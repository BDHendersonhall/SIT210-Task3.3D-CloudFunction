// -------------------------------------------------------------
// Publish and Subscribe - Buddy System
/* ------------------------------------------------------------*/

// Define the pin numbers for the LEDs
int led = D6; // Use led for 'wave'
int boardLed = D7; // use boardled for 'pat'

// Start with the setup function.

void setup() 
{

    pinMode(led,OUTPUT); // Our LED pin is output (lighting up the LED)
    pinMode(boardLed,OUTPUT); // Our on-board LED is output as well

    // Subscribe to our buddy's event using Particle.subscribe
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
    
    // Subscribe will listen for the event buddy_unique_event_name and, when it finds it, will run the function myHandler()
    // myHandler() is declared later in this program.
}

// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data)
{
    /* Particle.subscribe handlers are void functions, which means they don't return anything.
      They take two variables-- the name of your event, and any data that goes along with your event.
      In this case, the event will be "buddy_unique_event_name" and the data will be "wave" or "pat"

      Since the input here is a char, we can't do
         data=="wave"

      chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
      If they are the same, strcmp will return 0.
     */

    if (strcmp(data,"wave") == 0) 
    {
        // if your buddy's beam is intact, then turn your board LED off
        int delay_wave = 1000;
    
        for (int i = 0; i < 3; i++ ) 
        {
            digitalWrite(led,HIGH);
            delay(delay_wave);
            digitalWrite(led,LOW);
            delay(delay_wave);
        }
        delay(3000);
    }
    else if (strcmp(data,"pat") == 0)
    {
        int delay_pat = 200;
    
        for (int i = 0; i < 15; i++ ) 
        {
            digitalWrite(boardLed,HIGH);
            delay(delay_pat);
            digitalWrite(boardLed,LOW);
            delay(delay_pat);
        }
        delay(3000);
    }
    else 
    {
        // if the data is something else, don't do anything.
        // Really the data shouldn't be anything but those two listed above.
    }
}
