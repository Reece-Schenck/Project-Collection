"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Cpu = void 0;
const Hardware_1 = require("./Hardware");
const Ascii_1 = require("./Ascii");
class Cpu extends Hardware_1.Hardware {
    constructor(name, mmu, system) {
        super(name);
        this.cpuClockCount = 0;
        this.log("created");
        this.mmu = mmu;
        this.system = system;
        // Initialize registers
        this.accumulator = 0x00;
        this.xRegister = 0x00;
        this.yRegister = 0x00;
        this.programCounter = 0x0000;
        this.instructionRegister = '';
        this.zFlag = 1;
        this.lowOrder = 0x00;
        this.highOrder = 0x00;
        // Initialize pipeline step, Fetch is always first
        this.pipelineStep = 'FETCH';
        // Initialize helpers
        this.temp = 0x00;
        this.address = 0x0000;
        this.char = '';
        this.ascii = new Ascii_1.Ascii(this.char);
    }
    executeInstruction() {
        console.log("CPU State | Mode: 0 PC: " + this.programCounter + " IR: " + this.instructionRegister + " Acc: " +
            this.accumulator + " XReg: " + this.xRegister + " yReg: " + this.yRegister + " ZFlag: " + this.zFlag + " Step: " + this.pipelineStep);
        switch (this.pipelineStep) {
            case 'FETCH':
                this.instructionRegister = this.fetch(); // update the instruction register
                this.pipelineStep = 'DECODE';
                break;
            case 'DECODE':
                this.decode();
                this.pipelineStep = 'EXECUTE';
                break;
            case 'EXECUTE':
                this.execute();
                this.pipelineStep = 'INTERRUPT_CHECK';
                break;
            // write back is called from EE in execute
            case 'WRITE_BACK':
                this.writeBack();
                this.pipelineStep = 'INTERRUPT_CHECK';
                break;
            case 'INTERRUPT_CHECK':
                this.interruptCheck();
                this.pipelineStep = 'FETCH';
                break;
            default:
                console.error('Invalid pipeline stage:', this.pipelineStep);
        }
    }
    fetch() {
        const instructionAddress = this.programCounter;
        this.programCounter += 1;
        this.mmu.setMar(instructionAddress);
        this.mmu.readMemory();
        // return (this.mmu.getMdr()).toString();
        // hopefully properly formats hex data
        return parseInt((this.mmu.getMdr()).toString(16), 16).toString(16).toUpperCase().padStart(2, '0');
    }
    decode() {
        console.log('Decoding instruction:', this.instructionRegister);
        if (this.instructionRegister == "A9") {
            // program counter has already been incremented once in fetch
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.lowOrder = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "AD") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "8D") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "8A") {
            this.programCounter += 1; // increment program counter again
        }
        else if (this.instructionRegister == "98") {
            //this.programCounter += 1; // increment program counter again
        }
        else if (this.instructionRegister == "6D") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "A2") {
            // program counter has already been incremented once in fetch
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.lowOrder = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "AE") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "AA") {
            //this.programCounter += 1; // increment program counter again
        }
        else if (this.instructionRegister == "A0") {
            // program counter has already been incremented once in fetch
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.lowOrder = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "AC") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "A8") {
            this.programCounter += 1; // increment program counter again
        }
        else if (this.instructionRegister == "EA") {
            this.programCounter += 1; // increment program counter again
        }
        else if (this.instructionRegister == "00") {
            // break / does nothing
        }
        else if (this.instructionRegister == "EC") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "D0") {
            // program counter has already been incremented once in fetch
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.lowOrder = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "EE") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "FF") {
            // program counter has already been incremented once in fetch / last decode
            const instructionAddress = this.programCounter;
            //this.programCounter += 1; // increment program counter again
            this.mmu.setMar(instructionAddress);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr();
        }
    }
    execute() {
        console.log('Executing instruction:', this.instructionRegister);
        if (this.instructionRegister == "A9") {
            this.accumulator = this.lowOrder;
            // program counter has already been incremented in decode
        }
        else if (this.instructionRegister == "AD") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            // set data in memory to accumulator
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            this.accumulator = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "8D") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            // writes accumulator to given address
            this.mmu.writeImmediate(this.address, this.accumulator);
        }
        else if (this.instructionRegister == "8A") {
            this.accumulator = this.xRegister;
        }
        else if (this.instructionRegister == "98") {
            this.accumulator = this.yRegister;
        }
        else if (this.instructionRegister == "6D") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            // add data from address to accumulator
            this.accumulator += this.mmu.getMdr();
        }
        else if (this.instructionRegister == "A2") {
            this.xRegister = this.lowOrder;
        }
        else if (this.instructionRegister == "AE") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            // sets x register to data in given memory address
            this.xRegister = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "AA") {
            this.xRegister = this.accumulator;
        }
        else if (this.instructionRegister == "A0") {
            this.yRegister = this.lowOrder;
        }
        else if (this.instructionRegister == "AC") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            // sets x register to data in given memory address
            this.yRegister = this.mmu.getMdr();
        }
        else if (this.instructionRegister == "A8") {
            this.yRegister = this.accumulator;
        }
        else if (this.instructionRegister == "EA") {
            // does nothing
        }
        else if (this.instructionRegister == "00") {
            // break (fixed later)
            console.log("Program Complete!");
            this.system.stopSystem();
        }
        else if (this.instructionRegister == "EC") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            // if the value at the given memory matches the value in the x register, z = 0
            if (this.mmu.getMdr() == this.xRegister) {
                this.zFlag = 0;
            }
            else {
                this.zFlag = 1;
            }
        }
        else if (this.instructionRegister == "D0") {
            // gets the compliment of low order (flips and adds 1)
            const compliment = (0xFF - this.lowOrder) + 0x01;
            // only branches when z = 1
            if (this.zFlag != 0) {
                // goes back n lines in the program (n=compliment)
                // may have to subtract an extra 1 since decode increments program counter
                console.log("Looping");
                this.programCounter -= compliment;
            }
            else {
                console.log("Exiting loop");
            }
        }
        else if (this.instructionRegister == "EE") {
            this.lowOrder = this.temp;
            // decode again to get high order byte
            this.decode();
            this.highOrder = this.temp;
            // adjusting high order to be in the form of 0x0000 over 0x00
            if (this.highOrder != 0x00) {
                this.highOrder *= 0x100;
            }
            else {
                // accounts for high order being 0x00 which would otherwise mess up the adjustment
                this.highOrder = 0x0000;
            }
            // adds low and high order bytes together to gett address of data
            this.address = this.lowOrder + this.highOrder;
            this.mmu.setMar(this.address);
            this.mmu.readMemory();
            this.temp = this.mmu.getMdr() + 1;
            // call writeback to set the incremented value back in memory
            this.writeBack();
        }
        else if (this.instructionRegister == "FF") {
            // when x register is 1, the y register is printed to the consol as an int
            if (this.xRegister == 0x01) {
                // have to convert to string so it will print
                //process.stdout.write(this.yRegister.toString());      doesn't work
                console.log("Output: " + this.yRegister.toString());
                // when x register is 3, Print the 0x00 terminated string from the address in the operand
            }
            else if (this.xRegister == 0x03) {
                this.lowOrder = this.temp;
                // decode again to get high order byte
                this.decode();
                this.highOrder = this.temp;
                // adjusting high order to be in the form of 0x0000 over 0x00
                if (this.highOrder != 0x00) {
                    this.highOrder *= 0x100;
                }
                else {
                    // accounts for high order being 0x00 which would otherwise mess up the adjustment
                    this.highOrder = 0x0000;
                }
                // adds low and high order bytes together to gett address of data
                this.address = this.lowOrder + this.highOrder;
                this.mmu.setMar(this.address);
                this.mmu.readMemory();
                // converts the data in memory to a character then sets char to be that character
                this.ascii.setChar(this.ascii.byteToChar(this.mmu.getMdr()));
                const character = this.ascii.getChar();
                // writes char to the console
                //process.stdout.write(this.ascii.getChar());      doesn't work
                console.log("Output: " + character);
                this.programCounter += 2;
            }
        }
    }
    writeBack() {
        console.log('Writing back results to registers');
        // only for EE, after incrementing a byte it is then put back in memory
        this.mmu.writeImmediate(this.address, this.temp);
    }
    interruptCheck() {
        console.log('Checking for interrupts: ');
        //console.log(this.Keyboard.provideInterruptToCPU());
    }
    // Setters for registers
    setAccumulator(a) {
        this.accumulator = a;
    }
    setXRegister(x) {
        this.xRegister = x;
    }
    setYRegister(y) {
        this.yRegister = y;
    }
    setProgramCounter(pC) {
        this.programCounter = pC;
    }
    setInstructionRegister(iR) {
        this.instructionRegister = iR;
    }
    setZFlag(z) {
        this.zFlag = z;
    }
    // Getters for registers
    getAccumulator() {
        return this.accumulator;
    }
    getXRegister() {
        return this.xRegister;
    }
    getYRegister() {
        return this.yRegister;
    }
    getProgramCounter() {
        return this.programCounter;
    }
    getInstructionRegister() {
        return this.instructionRegister;
    }
    getZFlag() {
        return this.zFlag;
    }
    // Getter for pipeline step
    getPipelineStep() {
        return this.pipelineStep;
    }
    // Setter for pipeline step
    setPipelineStep(step) {
        this.pipelineStep = step;
    }
    callRead() {
        this.mmu.readMemory();
    }
    callWrite() {
        this.mmu.writeMemory();
    }
    writeImmediate(address, data) {
        this.mmu.writeImmediate(address, data);
    }
    displayMemory(fromAddress, toAddress) {
        this.mmu.displayMemory(fromAddress, toAddress);
    }
    pulse() {
        this.cpuClockCount++;
        console.log("received clock pulse - CPU Clock Count: " + this.cpuClockCount);
        // All pipeline steps happen in the pulse
        // Only one step is completed at any given time
        this.executeInstruction();
    }
}
exports.Cpu = Cpu;
//# sourceMappingURL=Cpu.js.map