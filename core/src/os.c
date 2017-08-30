#include <stddef.h>
#include <stdint.h>
#include "reg.h"
#include "systick.h"
#include "threads.h"
#include "stream.h"

#define puts(x) do {                       \
                   stream_write(USART,x);  \
                }while(0)


// Find all current organisms in the biosphere (biosphere = predefined region of memory)
// Sequentially execute their next instruction.
static void lifecycles()
{

}

void universe_loop()
{
    // Main processing loop.    
    while (1)
    {
	// Use individual functions/loops to execute universe tasks critical to every iteration.
	lifecycles();
    }
}

int main(void)
{
    stream_init(USART);

    if (thread_create(universe_loop, NULL) == -1) {
	puts("Universe thread creation failed\r\n");
    }

    SysTick_init();

    thread_start();

    return 0;
}
