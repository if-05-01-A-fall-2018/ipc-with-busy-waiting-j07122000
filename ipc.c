1. A race condition takes place, when two or more processes try to do something at the same time. This may lead to losing or overwriting data.


2.i. Disabling interrupts is only possible on a single core processor because on a multi core CPU, interrupts are disabled only on the core that has been instructed to do so.
2.ii. The user process could block the other processes if they’re working on a single core processor.

3.i. First Scenario: Process 1 waits until process 0 calls leave_region(). After the process 0 called the function, the process 1 can now enter the critical region.
Second Scenario: Process 0 waits till process 1 leaves the critical region, then process 1 waits for process 0 to leave the region.

3.ii. The variable loser is used to determine which process has to wait. In other words, the process who gets to do its stuff is the „winner“ and therefore, the one that has to wait is the loser.

3.iii

	#define ME 2

	while (True) {
	enter_region(ME);
	leave_region(ME);
	}


	int loser;
	bool interested[3];

void enter_region(int process)
{
	int other;
	int other2;

	if(process == 0)
	{
		other = 1;
		other2 = 2;
	}

	else if(process == 1)
	{
		other = 0;
		other2 = 2;
	}
	else
	{
		other = 0;
		other = 1;
	}
	
	interested[process] = true;
	loser = process;
	while (loser == process && interested[other] || loser == process && interested[other2]) ;
}