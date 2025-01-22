/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */

let storeTimer;
var debounce = function (fn, t) {
  return function (...args) {
    if (storeTimer) {
      clearTimeout(storeTimer);
    }
    storeTimer = setTimeout(() => {
      fn(...args);
      storeTimer = 0;
    }, t);
  };
};


/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */