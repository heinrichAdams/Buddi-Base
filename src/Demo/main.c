#include "../WindowHandler.h"
#include "../Utility.h"

// GLOBAL VARIABLES
// ---------------------------------------------
Window_Handler window_handler;
// ---------------------------------------------

// FUNCTION PROTOTYPES
// ---------------------------------------------
void Initialize_Buddi(Window_Handler* window_handler);
// ---------------------------------------------


int main(int argc, char* argv[])
{
    memset(&window_handler, 0,sizeof(Window_Handler));

    Initialize_Buddi(&window_handler);

    atexit(Clean);


    return 0;
}