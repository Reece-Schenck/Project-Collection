import { Hardware } from "./Hardware";
import {ClockListener} from "./imp/ClockListener";
import {Cpu} from "./Cpu";
import { Memory } from "./Memory";


export class Clock extends Hardware{
    private clockListenersCpu: Cpu[] = [];
    private clockListenersMemory: Memory[] = [];
    private intervalId: NodeJS.Timeout | null = null;

    constructor(name: string) {
        super(name);
    }

    // Add a listener to the clock
    addClockListenerCpu(listener: Cpu): void {
        this.clockListenersCpu.push(listener);
    }

    // Add a listener to the clock
    addClockListenerMemory(listener: Memory): void {
        this.clockListenersMemory.push(listener);
    }

    // Starts the clock with the specified interval
    startClock(interval: number): void {
        if(this.intervalId === null){
            setInterval(() => {
                for(var i of this.clockListenersCpu){
                    i.pulse();
                }
                for(var j of this.clockListenersMemory){
                    j.pulse();
                }
                this.pulse();
            }, interval);
        }
    }

    // Stops the clock
    stopClock(): void {
        if(this.intervalId !== null){
            clearInterval(this.intervalId);
            this.intervalId = null;
        }
    }

    pulse(): void{
        console.log("Clock Pulse Initialized");
    }
}