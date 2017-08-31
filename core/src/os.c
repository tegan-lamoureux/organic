#include <stddef.h>
#include <stdint.h>
#include "reg.h"
#include "systick.h"
#include "threads.h"
#include "stream.h"

#define puts(x) do {                       \
                   stream_write(USART,x);  \
                }while(0)


static void lifecycles()
{
    // Here's the base template for the Quine-like organism.
    // Eventually, want to compile and execute as machine code.
    // (The quine should copy its machine code, not the ASM.)
    ///////////////////////////////////////////////////////////
    //
    // start
    //
    asm("mov r0,r0"); // NOP instruction
    //
    // end
    // wow so fancy.
    //
    ///////////////////////////////////////////////////////////

    puts("executed..");

    for(int i = 0; i < 100000000; ++i); // debug delay for ~1sec
}

void universe_loop()
{
    // Main processing loop.
    
    while (1)
    {
	// Use individual functions/loops to execute universe tasks critical to every iteration.
	lifecycles();

	// Maybe spawn new threads/tasks here for each organism? Have the organism terminate its
	// own thread on death. Or have a reaper/garbage collector thread do it.

	// OR WHAT IF we have the quine execute its child program. instead of spawning threads from
	// the kernel to do it. Dig into the RTOS though, this may be the same as spawning a thread.
	// but the parent can still be the one to do it, instead of it being inherent to the kernel.
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
