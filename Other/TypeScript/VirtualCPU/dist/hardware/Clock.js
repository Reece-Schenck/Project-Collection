"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Clock = void 0;
const Hardware_1 = require("./Hardware");
class Clock extends Hardware_1.Hardware {
    constructor(name) {
        super(name);
        this.clockListenersCpu = [];
        this.clockListenersMemory = [];
        this.intervalId = null;
    }
    // Add a listener to the clock
    addClockListenerCpu(listener) {
        this.clockListenersCpu.push(listener);
    }
    // Add a listener to the clock
    addClockListenerMemory(listener) {
        this.clockListenersMemory.push(listener);
    }
    // Starts the clock with the specified interval
    startClock(interval) {
        if (this.intervalId === null) {
            setInterval(() => {
                for (var i of this.clockListenersCpu) {
                    i.pulse();
                }
                for (var j of this.clockListenersMemory) {
                    j.pulse();
                }
                this.pulse();
            }, interval);
        }
    }
    // Stops the clock
    stopClock() {
        if (this.intervalId !== null) {
            clearInterval(this.intervalId);
            this.intervalId = null;
        }
    }
    pulse() {
        console.log("Clock Pulse Initialized");
    }
}
exports.Clock = Clock;
//# sourceMappingURL=Clock.js.map