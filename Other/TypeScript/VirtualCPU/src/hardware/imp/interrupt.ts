export interface interrupt{
    // All interrupt generating devices are assigned an IRQ #
    irqNumber: number;

    // Priority of the device
    priority: number;

    // Name of the device generating the interrupt
    deviceName: string;

    // Input buffer to hold incoming data
    inputBuffer: string[];

    // Output buffer to hold outgoing data
    outputBuffer: string[];

    // Method to trigger the interrupt
    triggerInterrupt(): void;

    monitorKeys(): void
}