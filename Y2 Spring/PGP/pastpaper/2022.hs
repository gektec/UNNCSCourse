-- Here are the syntax errors in each function definition and how to fix them:

-- (i) The function name should start with a lowercase letter.
-- Fix: Change "F" to "f".
-- Corrected definition: f x y = (x+4) * x * (y-2)

-- (ii) The arrow "->" should be "=".
-- Fix: Change "->" to "=".
-- Corrected definition: f x = (\y -> x*(y+2))

-- (iii) The "=" is missing after "otherwise".
-- Fix: Add "=" after "otherwise".
-- Corrected definition:
-- g x y | x>y = x
--       | otherwise = y

-- (iv) The first clause of the function should have a different variable name for the first argument.
-- Fix: Change the second "x" to a different variable name, e.g., "y".
-- Corrected definition: 
-- h x (y:xs) = xs
-- h _ xs = xs

-- (v) j = foldr + 2
--     Error: foldr requires three arguments: a binary function, a starting value, and a list. Here, the list argument is missing.
--     Fix: You need to provide a list for foldr to operate on. For example:
--     haskell
-- j xs = foldr (+) 2 xs 




f x y = (x+4)*x*(y-2)
k x = \y->x*y+2
g x y |  x>y =x
      |  otherwise = y

h y (x:xs) = xs
h _ xs = xs
j xs = foldr (+) 2 xs



areUnique :: Eq a => [a]->Bool
areUnique [] = True
areUnique (x:xs)
    | elem x xs = False
    | otherwise = areUnique xs

-- Output: [(0,'c'),(1,'a'),(2,'t')]

indexList :: Num a => [a] -> [(Int,a)]
indexList = zip [0..]


data Matrix = Row [Float] Matrix | Null

m1 :: Matrix
m1 = Row [2.3, 4.5, 1.2] (Row [-0.4, 3.2, 3.4] Null)

m2 :: Matrix
m2 = Row [1.2,-1.0] (Row [4.5, -0.9] (Row [2.3, 1.8] Null))

legitMatrix :: Matrix -> Bool
legitMatrix Null = True
legitMatrix (Row xs Null) = True
legitMatrix (Row xs (Row ys rest)) = (length xs == length ys) && legitMatrix (Row ys rest)


insertColumn :: Matrix -> [Float] -> Matrix
insertColumn Null _  = Null
insertColumn (Row ys rest) (x:xs) = Row (x:ys) (insertColumn rest xs)

sizeMatrix :: Matrix -> (Int,Int)
sizeMatrix (Row xs Null) = (1, length xs)
sizeMatrix (Row xs rest) = (row+1, col)
    where (row, col) = sizeMatrix rest

emptyMatrix :: Int -> Matrix
emptyMatrix 0 = Null
emptyMatrix n = Row [] (emptyMatrix (n-1))

transposeMatrix :: Matrix -> Matrix
transposeMatrix Null = Null
transposeMatrix (Row xs Null) = insertColumn (emptyMatrix (length xs)) xs
transposeMatrix (Row xs rest) = insertColumn (transposeMatrix rest) xs


-- returnList :: Matrix -> [[Float]]
-- returnList Null = []
-- returnList (Row xs Null) = [xs]
-- returnList (Row xs rest) = xs : returnList rest

addRows :: [Float] -> [Float] -> [Float]
addRows xs ys = [x+y | (x,y) <- zip xs ys]
-- addRows xs ys = [x+y | x <- xs, y <- ys]
-- INCORRECT, will produce cartisan product

(+#+) :: Matrix -> Matrix -> Matrix
(+#+) Null Null = Null
(+#+) (Row xs rest1) (Row ys rest2) = Row (addRows xs ys) (rest1 +#+ rest2)


(+##+) :: Matrix -> Matrix -> Maybe Matrix
(+##+) mat1 mat2
    | not (legitMatrix mat1 && legitMatrix mat2) = Nothing
    | sizeMatrix mat1 /= sizeMatrix mat2 = Nothing
    | otherwise = Just(mat1 +#+ mat2)

showMatrix :: Matrix -> IO()
showMatrix mat = putStr (matrixString mat)

matrixString :: Matrix -> String
matrixString Null = "[]"
matrixString (Row xs Null) = "["++listString xs++"]\n"
matrixString (Row xs rest) = "["++listString xs++"]\n" ++ matrixString rest

listString :: [Float] -> String
listString [] = "]\n"
listString (x:xs) 
    | xs==[]=show x
    | otherwise = show x++"\t"++listString xs