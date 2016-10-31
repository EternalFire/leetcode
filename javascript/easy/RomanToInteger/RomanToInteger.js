
var roman_ = [
	{ code:'I', value: 1 },
	{ code:'V', value: 5 },
	{ code:'X', value: 10 },
	{ code:'L', value: 50 },
	{ code:'C', value: 100 },
	{ code:'D', value: 500 },
	{ code:'M', value: 1000 },
];
var getRomanValue = function(s) {
	for (var i = 0; i < roman_.length; i++) {
		var v = roman_[i];
		if (s.toUpperCase() === v.code) {
			return v.value;
		}		
	}
	return 0;
}
var isIXC = function(s) {
	return ['I', 'X', 'C'].some(function(e) {return e === s.toUpperCase();});
}

/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
	var check = Array.from(s).every(function(v){
		return roman_.some(function(e){ return e.code == v.toUpperCase(); });
	});

	if (check) {		
		// return Array.from(s).reverse().reduce(function(a, b, index, array) {
		// 	console.log(a,b,index);
		// 	var lastValue = getRomanValue(array[index - 1]);
		// 	var curValue = getRomanValue(array[index]);
		// 	var sum = typeof a == "string" ? lastValue : a;
			
		// 	if (lastValue <= curValue) {
		// 		sum += curValue;
		// 	} 
		// 	else if (isIXC(array[index])) {
		// 		sum -= curValue;				
		// 	}
		// 	console.log(lastValue, index, array[index], curValue, sum);
		// 	return sum;
		// }, );

		var sum = 0;
		// var array = Array.from(s).reverse();

		Array.from(s).reverse().map(function(e, index, array) {
			var lastValue = getRomanValue(array[index - 1]);
			var curValue = getRomanValue(array[index]);

			if (lastValue <= curValue) {
				sum += curValue;
			}
			else if (isIXC(array[index])) {
				sum -= curValue;
			}
		})
	}
	return 0;
};
console.log(romanToInt('i'));
