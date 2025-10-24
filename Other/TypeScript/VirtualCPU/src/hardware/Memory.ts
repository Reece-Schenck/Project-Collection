import { Hardware } from "./Hardware";
import {ClockListener} from "./imp/ClockListener";

export class Memory implements ClockListener{
    // Private array to store memory
    private memory: number[];

    // default mar and mdr
    private mar: number = 0x0000;
    private mdr: number = 0x00;

    constructor(memorySizeInBytes: number){
        // ensures that the array is not empty
        if(memorySizeInBytes <= 0){
            throw new Error("Memory size must be greater than 0.");
        }

        // Initialize the memory array in its default state
        this.memory = new Array(memorySizeInBytes).fill(0x00);  
    }

    // sets all the memory in the memory array back to the default value ('0x00')
    initializeMemory(): void {
        for(let i = 0; i < this.memory.length; i++){
            this.memory[i] = 0x00;
        }

        console.log(`[HW - RAM id: ${Hardware.id} - ${new Date().getTime()}]: Created - Addressable Space: ${this.memory.length}`);
    }

    // checks to make sure that the given address exists, throws error if it doesn't
    private validateAddress(address: number): void {
        if(address < 0 || address >= this.memory.length){
            // commented out as it is handeled more elegantly elsewhere
            //throw new Error('Invalid memory address: ' + address);
        }
    }

    // I asked ChatGPT for how to only allow hexidecimal numbers:
    private validateData(data: number): void {
        if(!/^[0-9A-Fa-f]{2}$/.test(data.toString())){
            throw new Error('Invalid data: ${data}. Data must be a hexadecimal string of two characters.');
        }
    }

    // reads the data at the given address number in the memory array
    readMemory(address: number): number {
        this.validateAddress(address);
        return this.memory[address];
    }

    // writes given data to given address number in the memory array
    writeMemory(address: number, data: number): void {
        this.validateAddress(address);
        this.validateData(data);
        this.memory[address] = data;
    }

    // I had ChatGPT help me with the for-loop, and fixing both formattedHexValue & logMessage
    // displays memory from 0x00 - 0x14
    displayMemory(fromAddress: number, toAddress: number): void {
        
        console.log(`[HW - MMU id: 0 - ${Date.now()}]: Initialized Memory`);

        console.log(`[HW - MMU id: 0 - ${Date.now()}]: Memory Dump: Debug`);
        console.log(`[HW - MMU id: 0 - ${Date.now()}]: --------------------------------------`);

        for (let address = fromAddress; address <= toAddress; address++) {
            const data = this.memory[address];

            // Used ChatGPT to help me with properly displaying the data in proper hex formatting
            console.log(`[HW - MMU id: 0 - ${Date.now()}]: Addr ${Hardware.hexLog(address, 4)}: | 0x${parseInt(data.toString(16), 16).toString(16).toUpperCase().padStart(2, '0')}`);
        }

        console.log(`[HW - MMU id: 0 - ${Date.now()}]: --------------------------------------`);
        console.log(`[HW - MMU id: 0 - ${Date.now()}]: Memory Dump: Complete`);
    }

    // displays memory at given address
    displayMemoryTarget(address: number): void {
            const hexValue = this.readMemory(address);
            const formattedHexValue = hexValue !== undefined ? Hardware.hexLog(parseInt(hexValue.toString(), 16), 4) : 'ERR [hexValue conversion]: number undefined';
      
            // address = (0x0000) and data = (0x00)
            const logMessage = `[HW - RAM id: ${Hardware.id} - ${new Date().getTime()}]: Address: ${Hardware.hexLog(address, 4)} Contains Value: ${formattedHexValue}`;
            console.log(logMessage);
    }

    pulse(): void {
        console.log("received clock pulse");
    }

    // sets all memory addresses to 0x0000
    reset(): void {
        for(let i = 0; i < this.memory.length; i++){
            this.memory[i] = 0x00;
        }
        this.mar = 0x0000;
        this.mdr = 0x00;
    }

    public getMar(): number{
        return this.mar;
    }

    public setMar(newMar: number): void {
        this.mar = newMar;
    }

    public getMdr(): number {
        return this.mdr;
    }

    public setMdr(newMdr: number): void {
        this.mdr = newMdr;
    }

    read(): void {
        this.setMdr(this.memory[this.getMar()]);
    }

    write(): void {
        this.memory[this.getMar()] = this.getMdr();
    }
}