class Calculator {
    // @param {number} value
    constructor(value) {
        this.result = value;
    }
    
    //-------- @return {Calculator} -------- STARTS
    // @param {number} value
    add(value){
        this.result += value;
        return this;
    }
    
    // @param {number} value
    subtract(value){
        this.result -= value;
        return this;
    }
    
    // @param {number} value 
    multiply(value) {
        this.result *= value;
        return this;
    }
    
    // @param {number} value
    divide(value) {
        if(value == 0) throw new Error('Division by zero is not allowed');
        this.result /= value;
        return this;
    }
    
    // @param {number} value
    power(value) {
        this.result = Math.pow(this.result, value);
        return this;
    }
    
    //-------- @return {Calculator} -------- ENDS

    // @return {number}
    getResult() {
        return this.result;
    }
}