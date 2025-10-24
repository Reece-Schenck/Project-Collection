"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Mmu = void 0;
const Memory_1 = require("./Memory");
class Mmu {
    constructor(memorySizeInBytes) {
        this.memory = new Memory_1.Memory(memorySizeInBytes);
    }
    // Set MAR with a 16-bit address in one cycle
    setMarFrom16BitAddress(address) {
        this.memory.setMar(address);
    }
    // Set MAR with two single bytes in little-endian format
    setMarFromLittleEndian(bytes) {
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
    setMarFromAddressString(address) {
        this.memory.setMar(parseInt(address, 16));
    }
    // Example function that uses setMarFromAddressString for reuse
    setMarFromHexString(hexAddress) {
        this.setMarFromAddressString(hexAddress);
    }
    readMemory() {
        this.memory.read();
    }
    writeMemory() {
        this.memory.write();
    }
    getMar() {
        return this.memory.getMar();
    }
    setMar(newMar) {
        this.memory.setMar(newMar);
    }
    getMdr() {
        return this.memory.getMdr();
    }
    setMdr(newMdr) {
        this.memory.setMdr(newMdr);
    }
    writeImmediate(address, data) {
        this.memory.setMar(address);
        this.memory.setMdr(data);
        this.memory.write();
    }
    displayMemory(fromAddress, toAddress) {
        this.memory.displayMemory(fromAddress, toAddress);
    }
}
exports.Mmu = Mmu;
//# sourceMappingURL=Mmu.js.map