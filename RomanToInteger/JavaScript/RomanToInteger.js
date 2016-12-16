
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
		var sum = 0;

		// Array.from(s).reverse().forEach(function(e, index, array) {
		// 	var curValue = getRomanValue(array[index]);
		// 	var lastValue = index > 0 ? getRomanValue(array[index - 1]) : 0;

		// 	if (lastValue <= curValue) {
		// 		sum += curValue;
		// 	}
		// 	else if (isIXC(array[index])) {
		// 		sum -= curValue;
		// 	}
		// })
		// return sum;

		if (s.length == 1) { return getRomanValue(s); }
		
		var lastValue = getRomanValue(s[s.length - 1]); // last calculated
		sum = lastValue;

		for (var i = s.length - 2; i >= 0; i--) {		
			
			var curValue = getRomanValue(s[i]);

			if (lastValue <= curValue) {
				sum += curValue;
			}
			else if (isIXC(s[i])) {
				sum -= curValue;
			}

			lastValue = curValue;
		}

		return sum;
	}
	return 0;
};

console.log(romanToInt('DCXXI'));