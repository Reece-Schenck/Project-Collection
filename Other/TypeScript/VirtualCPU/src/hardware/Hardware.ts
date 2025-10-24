import {System} from "../System";
import {Cpu} from "./Cpu";
import { Memory } from "./Memory";

export class Hardware {
    private static nextId = 1;
    readonly id: number;
    name: string;
    debug: boolean = true;

    hexNum: string;
    static id: any;

    constructor(name: string){
        this.id = Hardware.nextId++;
        this.name = name;
    }

    setDebug(debug: boolean): void {
        this.debug = debug;
    }

    log(message: string): void {
        if(this.debug){
            const timestamp = new Date().getTime();
            console.log(`[HW - ${this.constructor.name} id: ${this.id} - ${timestamp}]: ${message}`);
        }
    }

    // takes number and length(2 or 4) and returns the hexidecimal string
    // for some reason the number has to be lowercased for length, IDK why
    static hexLog(number: number, length: number): string {
        if (length <= 0 || length % 2 !== 0) {
            throw new Error("Desired length must be a positive even number.");
        }

        const hexString = number.toString(16).toUpperCase();
        const paddingLength = Math.max(length - hexString.length, 0);
        const paddedHexString = '0'.repeat(paddingLength) + hexString;
    
        return `0x${paddedHexString}`;    
    }

}