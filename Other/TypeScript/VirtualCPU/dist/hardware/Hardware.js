"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Hardware = void 0;
class Hardware {
    constructor(name) {
        this.debug = true;
        this.id = Hardware.nextId++;
        this.name = name;
    }
    setDebug(debug) {
        this.debug = debug;
    }
    log(message) {
        if (this.debug) {
            const timestamp = new Date().getTime();
            console.log(`[HW - ${this.constructor.name} id: ${this.id} - ${timestamp}]: ${message}`);
        }
    }
    // takes number and length(2 or 4) and returns the hexidecimal string
    // for some reason the number has to be lowercased for length, IDK why
    static hexLog(number, length) {
        if (length <= 0 || length % 2 !== 0) {
            throw new Error("Desired length must be a positive even number.");
        }
        const hexString = number.toString(16).toUpperCase();
        const paddingLength = Math.max(length - hexString.length, 0);
        const paddedHexString = '0'.repeat(paddingLength) + hexString;
        return `0x${paddedHexString}`;
    }
}
exports.Hardware = Hardware;
Hardware.nextId = 1;
//# sourceMappingURL=Hardware.js.map