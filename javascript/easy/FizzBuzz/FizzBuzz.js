/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    if (n <= 0) {
        return [];
    }
    
    var multipilesN = function(number, N) { return number % N === 0; }
    var multipiles3 = function(number) { return multipilesN(number, 3); }
    var multipiles5 = function(number) { return multipilesN(number, 5); }
    
    return Array.from({length: n}, (v, k) => (k + 1)).map(function(v, index) {
        if (multipiles3(v) && multipiles5(v)) return "FizzBuzz";
        if (multipiles3(v)) return "Fizz";
        if (multipiles5(v)) return "Buzz";
        return v + "";
    });
};