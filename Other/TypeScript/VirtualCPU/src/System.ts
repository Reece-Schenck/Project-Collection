// import statements for hardware
import { Clock } from "./hardware/Clock";
import {Cpu} from "./hardware/Cpu";
import { Hardware } from "./hardware/Hardware";
import { Memory } from "./hardware/Memory";
import { Mmu } from "./hardware/Mmu";
import { Keyboard } from "./hardware/Keyboard";
import { interruptController } from "./hardware/InterruptController";


/*
    Constants
 */
// Initialization Parameters for Hardware
// Clock cycle interval
const CLOCK_INTERVAL= 500;               // This is in ms (milliseconds) so 1000 = 1 second, 100 = 1/10 second
                                        // A setting of 100 is equivalent to 10hz, 1 would be 1,000hz or 1khz,
                                        // .001 would be 1,000,000 or 1mhz. Obviously you will want to keep this
                                        // small, I recommend a setting of 100, if you want to slow things down
                                        // make it larger.


export class System extends Hardware{

    private _Memory : Memory = null;

    private _CPU : Cpu = null;
    
    public running: boolean = false;

    private _MMU: Mmu = null;

    private _Keyboard: Keyboard = null;

    private _InterruptController: interruptController;

    constructor(name: string) {
        super(name);
        //removed forLab 1
        //console.log("Hello TSIRAM!");

        const memorySizeInBytes = 1024; // 1 KB of memory

        this._MMU = new Mmu(memorySizeInBytes);

        this._CPU = new Cpu(name, this._MMU, this);

        this._Memory = new Memory(memorySizeInBytes);

        // irq = 1, priority = 10
        this._Keyboard = new Keyboard(1, 10, 'keyboard', this._InterruptController);
        
        /*
        Start the system (Analogous to pressing the power button and having voltages flow through the components)
        When power is applied to the system clock, it begins sending pulses to all clock observing hardware
        components so they can act on each clock cycle.
         */

        this.startSystem();
    }

    public startSystem(): boolean {
        this.log("created");
        this._CPU.setDebug(false);

        // code from old labs, commented out to reduce clutter

        // sets all the memory to the default values of 0x00
        this._Memory.initializeMemory();

        // serches memory addresses 0x00-0x14
        //this._Memory.displayMemory(0x0000, 0x0014);

        // used to search specific memory address
        //this._Memory.displayMemoryTarget(0x10000);

        // Write the given static program into the first 10 bytes of memory
        //this._CPU.writeImmediate(0x0000, 0xA9);
        //this._CPU.writeImmediate(0x0001, 0x0D);
        //this._CPU.writeImmediate(0x0002, 0xA9);
        //this._CPU.writeImmediate(0x0003, 0x1D);
        //this._CPU.writeImmediate(0x0004, 0xA9);
        //this._CPU.writeImmediate(0x0005, 0x2D);
        //this._CPU.writeImmediate(0x0006, 0xA9);
        //this._CPU.writeImmediate(0x0007, 0x3F);
        //this._CPU.writeImmediate(0x0008, 0xA9);
        //this._CPU.writeImmediate(0x0009, 0xFF);
        //this._CPU.writeImmediate(0x000A, 0x00);

        //this._CPU.displayMemory(0x0000, 0x000F);

        // test program 1 - works
        /*
        // load constant 0
        this._CPU.writeImmediate(0x0000, 0xA9);
        this._CPU.writeImmediate(0x0001, 0x00);
        // write acc (0) to 0040
        this._CPU.writeImmediate(0x0002, 0x8D);
        this._CPU.writeImmediate(0x0003, 0x40);
        this._CPU.writeImmediate(0x0004, 0x00);
        // load constant 1
        this._CPU.writeImmediate(0x0005, 0xA9);
        this._CPU.writeImmediate(0x0006, 0x01);
        // add acc (?) to mem 0040 (?)
        this._CPU.writeImmediate(0x0007, 0x6D);
        this._CPU.writeImmediate(0x0008, 0x40);
        this._CPU.writeImmediate(0x0009, 0x00);
        // write acc ? to 0040
        this._CPU.writeImmediate(0x000A, 0x8D);
        this._CPU.writeImmediate(0x000B, 0x40);
        this._CPU.writeImmediate(0x000C, 0x00);
        // Load y from memory 0040
        this._CPU.writeImmediate(0x000D, 0xAC);
        this._CPU.writeImmediate(0x000E, 0x40);
        this._CPU.writeImmediate(0x000F, 0x00);
        // Load x with constant (1) (to make the first system call)
        this._CPU.writeImmediate(0x0010, 0xA2);
        this._CPU.writeImmediate(0x0011, 0x01);
        // make the system call to print the value in the y register (3)
        this._CPU.writeImmediate(0x0012, 0xFF);
        // Load x with constant (3) (to make the second system call for the string)
        this._CPU.writeImmediate(0x0013, 0xA2);
        this._CPU.writeImmediate(0x0014, 0x03);
        // make the system call to print the value in the y register (3)
        this._CPU.writeImmediate(0x0015, 0xFF);
        this._CPU.writeImmediate(0x0016, 0x50);
        this._CPU.writeImmediate(0x0017, 0x00);
        // test DO (Branch Not Equal) will be NE and branch (0x0021 contains 0x20 and xRegcontains B2)
        this._CPU.writeImmediate(0x0018, 0xD0);
        this._CPU.writeImmediate(0x0019, 0xED);
        // globals
        this._CPU.writeImmediate(0x0050, 0x2C);
        this._CPU.writeImmediate(0x0052, 0x00);
        this._Memory.displayMemory(0x0000, 0x001A);
        this.log("---------------------------")
        this._Memory.displayMemory(0x0050, 0x0053);
        */

        // test program 2 - works
        /*
        // load constant 3
        this._CPU.writeImmediate(0x0000, 0xA9);
        this._CPU.writeImmediate(0x0001, 0x0A);
        // write acc (3) to 0040
        this._CPU.writeImmediate(0x0002, 0x8D);
        this._CPU.writeImmediate(0x0003, 0x40);
        this._CPU.writeImmediate(0x0004, 0x00);
        // :loop
        // Load y from memory (3)
        this._CPU.writeImmediate(0x0005, 0xAC);
        this._CPU.writeImmediate(0x0006, 0x40);
        this._CPU.writeImmediate(0x0007, 0x00);
        // Load x with constant (1) (to make the first system call)
        this._CPU.writeImmediate(0x0008, 0xA2);
        this._CPU.writeImmediate(0x0009, 0x01);
        // make the system call to print the value in the y register (3)
        this._CPU.writeImmediate(0x000A, 0xFF);
        // Load x with constant (3) (to make the second system call for the string)
        this._CPU.writeImmediate(0x000B, 0xA2);
        this._CPU.writeImmediate(0x000C, 0x03);
        // make the system call to print the value in the y register (3)
        this._CPU.writeImmediate(0x000D, 0xFF);
        this._CPU.writeImmediate(0x000E, 0x50);
        this._CPU.writeImmediate(0x000F, 0x00);
        // load the string
        // 0A 48 65 6c 6c 6f 20 57 6f 72 6c 64 21
        this._CPU.writeImmediate(0x0050, 0x0A);
        this._CPU.writeImmediate(0x0051, 0x48);
        this._CPU.writeImmediate(0x0052, 0x65);
        this._CPU.writeImmediate(0x0053, 0x6C);
        this._CPU.writeImmediate(0x0054, 0x6C);
        this._CPU.writeImmediate(0x0055, 0x6F);
        this._CPU.writeImmediate(0x0056, 0x20);
        this._CPU.writeImmediate(0x0057, 0x57);
        this._CPU.writeImmediate(0x0058, 0x6F);
        this._CPU.writeImmediate(0x0059, 0x72);
        this._CPU.writeImmediate(0x005A, 0x6C);
        this._CPU.writeImmediate(0x005B, 0x64);
        this._CPU.writeImmediate(0x005C, 0x21);
        this._CPU.writeImmediate(0x005D, 0x0A);
        this._CPU.writeImmediate(0x005E, 0x00);
        this._Memory.displayMemory(0x0000, 0x0010);
        this.log("---------------------------")
        this._Memory.displayMemory(0x0040, 0x0043);
        this.log("---------------------------")
        this._Memory.displayMemory(0x0050, 0x005C);
        */

        // test program 3 (fibonacci sequence from lab 2) - works
        this._CPU.writeImmediate(0x0000, 0xA9);
        this._CPU.writeImmediate(0x0001, 0x04);
        this._CPU.writeImmediate(0x0002, 0x8D);
        this._CPU.writeImmediate(0x0003, 0x52);
        this._CPU.writeImmediate(0x0004, 0x00);
        this._CPU.writeImmediate(0x0005, 0xA9);
        this._CPU.writeImmediate(0x0006, 0x00);
        this._CPU.writeImmediate(0x0007, 0x8D);
        this._CPU.writeImmediate(0x0008, 0x50);
        this._CPU.writeImmediate(0x0009, 0x00);
        this._CPU.writeImmediate(0x000A, 0xA9);
        this._CPU.writeImmediate(0x000B, 0x01);
        this._CPU.writeImmediate(0x000C, 0x8D);
        this._CPU.writeImmediate(0x000D, 0x51);
        this._CPU.writeImmediate(0x000E, 0x00);
        this._CPU.writeImmediate(0x000F, 0xA9);
        this._CPU.writeImmediate(0x0010, 0x01);
        this._CPU.writeImmediate(0x0011, 0x8D);
        this._CPU.writeImmediate(0x0012, 0x53);
        this._CPU.writeImmediate(0x0013, 0x00);
        this._CPU.writeImmediate(0x0014, 0xA9);
        this._CPU.writeImmediate(0x0015, 0x01);
        this._CPU.writeImmediate(0x0016, 0x8D);
        this._CPU.writeImmediate(0x0017, 0x54);
        this._CPU.writeImmediate(0x0018, 0x00);
        this._CPU.writeImmediate(0x0019, 0xAC);
        this._CPU.writeImmediate(0x001A, 0x50);
        this._CPU.writeImmediate(0x001B, 0x00);
        this._CPU.writeImmediate(0x001C, 0x98);
        this._CPU.writeImmediate(0x001D, 0xA2);
        this._CPU.writeImmediate(0x001E, 0x01);
        this._CPU.writeImmediate(0x001F, 0xFF);
        this._CPU.writeImmediate(0x0020, 0x6D);
        this._CPU.writeImmediate(0x0021, 0x51);
        this._CPU.writeImmediate(0x0022, 0x00);
        this._CPU.writeImmediate(0x0023, 0x8D);
        this._CPU.writeImmediate(0x0024, 0x50);
        this._CPU.writeImmediate(0x0025, 0x00);
        this._CPU.writeImmediate(0x0026, 0xAC);
        this._CPU.writeImmediate(0x0027, 0x51);
        this._CPU.writeImmediate(0x0028, 0x00);
        this._CPU.writeImmediate(0x0029, 0xFF);
        this._CPU.writeImmediate(0x002A, 0x98);
        this._CPU.writeImmediate(0x002B, 0x6D);
        this._CPU.writeImmediate(0x002C, 0x50);
        this._CPU.writeImmediate(0x002D, 0x00);
        this._CPU.writeImmediate(0x002E, 0x8D);
        this._CPU.writeImmediate(0x002f, 0x51);
        this._CPU.writeImmediate(0x0030, 0x00);
        this._CPU.writeImmediate(0x0031, 0xAD);
        this._CPU.writeImmediate(0x0032, 0x54);
        this._CPU.writeImmediate(0x0033, 0x00);
        this._CPU.writeImmediate(0x0034, 0x6D);
        this._CPU.writeImmediate(0x0035, 0x53);
        this._CPU.writeImmediate(0x0036, 0x00);
        this._CPU.writeImmediate(0x0037, 0xAA);
        this._CPU.writeImmediate(0x0038, 0x8D);
        this._CPU.writeImmediate(0x0039, 0x54);
        this._CPU.writeImmediate(0x003A, 0x00);
        this._CPU.writeImmediate(0x003B, 0xEC);
        this._CPU.writeImmediate(0x003C, 0x52);
        this._CPU.writeImmediate(0x003D, 0x00);
        this._CPU.writeImmediate(0x003E, 0xD0);
        this._CPU.writeImmediate(0x003F, 0xD9);
        this._CPU.writeImmediate(0x0040, 0x00);
        this.log("---------------------------")
        this._Memory.displayMemory(0x0000, 0x0040);
        this.log("---------------------------")
        this._Memory.displayMemory(0x0041, 0x005F);

        const clock = new Clock("clock");

        // 1 second interval
        const CLOCK_INTERVAL = 1000;

        clock.startClock(CLOCK_INTERVAL);

        clock.addClockListenerCpu(this._CPU);
        clock.addClockListenerMemory(this._Memory);
        
        return true;
    }

    public stopSystem(): boolean {
        return false;
    }
}

let system: System = new System("Test System");
