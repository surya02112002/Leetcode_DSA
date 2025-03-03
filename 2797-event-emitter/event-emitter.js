class EventEmitter {
    constructor() {
        this.events = {}
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!(eventName in this.events)) {
            this.events[eventName] = []
        }

        const obj = {
            fn: callback,
            priority: this.events[eventName].length > 0 ? this.events[eventName][this.events[eventName].length - 1].priority + 1 : 0,
        }

        this.events[eventName].push(obj)



        return {
            unsubscribe: () => {
                for (let key in this.events) {
                    if (key === eventName) {
                        this.events[eventName] = this.events[eventName]?.filter((item) => item.priority != obj.priority)
                    }
                }
                if (this.events[eventName]?.length === 0) {
                    delete this.events[eventName]
                }

                return undefined;
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const result = [];
        for (let key in this.events) {
            if (key === eventName) {
                this.events[eventName]?.forEach(item => {
                    result.push(item.fn(...args))
                })
            }
        }

        return result
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */