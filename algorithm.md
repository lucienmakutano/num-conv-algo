# start

Function DecimalToBinary (decNum) {
var decimalPointResult
var wholeNumberResult

    Numbers = Split (decNum, basedOn=".")

If Length (Numbers) is great than 2
Return “wrong number format"

If Length (Numbers) is equal to 2
var decimalPoint = getAtIndex (Numbers, 1)
fractionResult = convertDecimalPoint (decimalPoint)

var wholeNumber = getAtIndex (Numbers, 0)
wholeNumberResult = convertWholeNumber (wholeNumber)

return Concat (wholeNumberResult, decimalPointResult, orientation="end")
}

Function convertWholeNumber (wholeNum) {
var result
While wholeNum is not equal to 0
If wholeNum modulus 2 is equal to 0
Concat (result, “0", orientation="front")
Else
Concat (result, “1", orientation="front")
wholeNum = RoundDown (wholeNum / 2)
return result
}
Function convertDecimalPoint (decPoint) {
var finalResult
var numbers = Split (decPoint, basedOn=".")
var length = Length (numbers)
var counter = 0

While length is equal to 2 and counter is less than 6
var result = decPoint \* 2
arr = Split (result, basedOn=".")
var wholeNum = getAtIndex (arr, 0)
finalResult = Concat (finalResult, wholeNum, orientation="end")
decPoint = result – wholeNum
length = Length (arr)
counter = counter + 1
finalResult = Concat (finalResult, “.", orientation=“front")
return finalResult
}

# end
