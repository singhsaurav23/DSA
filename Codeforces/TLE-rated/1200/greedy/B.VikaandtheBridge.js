//maintain two max for each color and divide by 2 first max and then for ech color find minimum among maximum steps

function solve() {
    var t = parseInt(readline());

    for (var testCase = 0; testCase < t; testCase++) {
        var input = readline().split(' ');
        var k = parseInt(input[0]);
        var n = parseInt(input[1]);
        var arr = readline().split(' ');

        var keyValuePairs = {};
        var lastSeen = {};

        for (var i = 0; i < k; i++) {
            var num = arr[i];

            if (lastSeen[num] !== undefined) {
                var lastIndex = lastSeen[num];
                var gap = i - lastIndex - 1;

                if (keyValuePairs[num]) {
                    var ma1 = keyValuePairs[num][0];
                    var ma2 = keyValuePairs[num][1];

                    if (gap > ma1) {
                        keyValuePairs[num] = [gap, ma1];
                    } else if (gap > ma2) {
                        keyValuePairs[num] = [ma1, gap];
                    }
                } else {
                    keyValuePairs[num] = [gap, 0];
                }
            } else {
                if (!keyValuePairs[num]) {
                    keyValuePairs[num] = [i, 0];
                }
            }

            lastSeen[num] = i;
        }

        for (var num in lastSeen) {
            var lastIndex = lastSeen[num];
            var gap = k - lastIndex - 1;

            if (keyValuePairs[num] !== undefined) {
                var ma1 = keyValuePairs[num][0];
                var ma2 = keyValuePairs[num][1];

                if (gap > ma1) {
                    keyValuePairs[num] = [gap, ma1];
                } else if (gap > ma2) {
                    keyValuePairs[num] = [ma1, gap];
                }
            } else {
                keyValuePairs[num] = [gap, 0];
            }
        }

        var result = 100000;
        for (var num in keyValuePairs) {
            var x = keyValuePairs[num][0];
            var y = keyValuePairs[num][1];

            var z = Math.floor(x / 2);
            result = Math.min(result, Math.max(z, y));
        }

        print(result);
    }
}

solve();