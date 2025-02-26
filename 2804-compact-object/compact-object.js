/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        
        return obj
            .map(compactObject) 
            .filter(Boolean);  
    } else if (typeof obj === "object" && obj !== null) {
        
        const result = {};
        for (const key in obj) {
            const value = compactObject(obj[key]); 
            if (Boolean(value)) {                 
                result[key] = value;
            }
        }
        return result;
    }
   
    return obj;
};