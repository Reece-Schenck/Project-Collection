import { Memory } from "./Memory";
import { Cpu } from "./Cpu";

export class Mmu {
    private memory: Memory;
    private cpu: Cpu;

    constructor(memorySizeInBytes: number) {
        this.memory = new Memory(memorySizeInBytes);
    }

    // Set MAR with a 16-bit address in one cycle
    setMarFrom16BitAddress(address: number): void {
        this.memory.setMar(address);
    }

    // Set MAR with two single bytes in little-endian format
    setMarFromLittleEndian(bytes: string[]): void {
        if (bytes.length !== 2) {
            throw new Error("Invalid number of bytes provided for little-endian format.");
        }
        // Concatenate bytes in little-endian order
        const littleEndianAddress = bytes[1] + bytes[0];
        this.memory.setMar(parseInt(littleEndianAddress, 16));
    }

    // Asked chat for some help with setting Mar from Hex 
    // As I came across multiple errors
    // Common functionality to set MAR from an address string
    private setMarFromAddressString(address: string): void {
        this.memory.setMar(parseInt(address, 16));
    }

    // Example function that uses setMarFromAddressString for reuse
    setMarFromHexString(hexAddress: string): void {
        this.setMarFromAddressString(hexAddress);
    }

    readMemory(): void {
        this.memory.read();
    }

    writeMemory(): void {
        this.memory.write();
    }

    public getMar(): number {
        return this.memory.getMar();
    }

    public setMar(newMar: number): void {
        this.memory.setMar(newMar);
    }

    public getMdr(): number {
        return this.memory.getMdr();
    }

    public setMdr(newMdr: number): void {
        this.memory.setMdr(newMdr);
    }

    writeImmediate(address: number, data: number): void {
        this.memory.setMar(address);
        this.memory.setMdr(data);
        this.memory.write();
    }

    displayMemory(fromAddress: number, toAddress: number): void {
        this.memory.displayMemory(fromAddress, toAddress);
    }
}