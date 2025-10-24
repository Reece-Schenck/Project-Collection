import { Hardware } from "./Hardware";
import { interrupt } from "./imp/interrupt";

export class interruptController extends Hardware{

    // had ChatGPT help me with the functions

    private interruptQueue: interrupt[] = [];
    private hardwareWithInterrupts: String[] = [];

    constructor() {
        super('InterruptController');
    }

    // Register hardware that generates interrupts
    registerInterruptSource(hardware: String): void {
        this.hardwareWithInterrupts.push(hardware);
    }

    // Queue an interrupt
    acceptInterrupt(interrupt: interrupt): void {
        this.interruptQueue.push(interrupt);
        this.interruptQueue.sort((a, b) => b.priority - a.priority); // Sort by priority (higher priority first)
    }

    // Provide the highest priority interrupt to the CPU
    provideInterruptToCPU(): interrupt | undefined {
        return this.interruptQueue.shift(); // Remove and return the highest priority interrupt
    }

    pulse(){
        return this.provideInterruptToCPU();
    }
}