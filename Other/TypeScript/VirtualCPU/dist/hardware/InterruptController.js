"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.interruptController = void 0;
const Hardware_1 = require("./Hardware");
class interruptController extends Hardware_1.Hardware {
    constructor() {
        super('InterruptController');
        // had ChatGPT help me with the functions
        this.interruptQueue = [];
        this.hardwareWithInterrupts = [];
    }
    // Register hardware that generates interrupts
    registerInterruptSource(hardware) {
        this.hardwareWithInterrupts.push(hardware);
    }
    // Queue an interrupt
    acceptInterrupt(interrupt) {
        this.interruptQueue.push(interrupt);
        this.interruptQueue.sort((a, b) => b.priority - a.priority); // Sort by priority (higher priority first)
    }
    // Provide the highest priority interrupt to the CPU
    provideInterruptToCPU() {
        return this.interruptQueue.shift(); // Remove and return the highest priority interrupt
    }
    pulse() {
        return this.provideInterruptToCPU();
    }
}
exports.interruptController = interruptController;
//# sourceMappingURL=InterruptController.js.map