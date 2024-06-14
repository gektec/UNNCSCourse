s :: Int -> Float
s i
    | even i  = -1
    | otherwise = 1

piSub :: Int -> [Float]
piSub k = [s (k+i)/ fromIntegral (2*k -1 +2*i) | i <- [0..]]


getPi :: Int -> Float
getPi n = 4 * sum (take n (piSub 0))

type Emp = (Int, String, Int, Int, String)

e1 :: Emp
e1 = (2, "Arnold Jones", 30000, 1, "Programmer")

empType :: Emp -> Int
empType (_, _, _, typ, _) = typ

empInc :: Emp -> Int
empInc (_, _, income, _, _) = income

empByType :: [Emp] -> Int -> [Emp]
empByType [] _ = []
empByType ((a,b,c,d,e):xs) typ
    | d == typ = (a,b,c,d,e):empByType xs typ
    | otherwise = empByType xs typ


taxCalcs :: [Emp -> Int]
taxCalcs = [\x -> max (div (empInc x - 10000) 10) 0,
            \x -> max (div (empInc x - 15000) 8) 0,
            \x -> max (div (empInc x - 5000) 12) 0 ]


calcTax :: Emp -> Int
calcTax emp = ((!!) taxCalcs ((empType emp)-1)) emp

empsTax :: [Emp] -> [Int]
empsTax [] = []
empsTax (e:es) = calcTax e:empsTax es
-- empsTax es = map calcTax es

incTaxByType es t = (t, sum(map empInc ets), sum(empsTax ets))
    where
        ets = empByType es t

incTaxTotals :: [Emp] -> [(Int,Int,Int)]
incTaxTotals emps = map (incTaxByType emps) [1,2,3]

showIncTaxTotals :: [Emp] -> IO()
showIncTaxTotals emps = putStr (fullStr emps)

fullStr :: [Emp] -> String
fullStr emps = "Total income and tax by employee type:\nType\tIncome\tTax\n"++dataStr (incTaxTotals emps)++"End of report\n"

dataStr :: [(Int,Int,Int)] -> String
dataStr [] = []
dataStr ((typ, inc, tax):xs) = show typ++['\t']++show inc++['\t']++show tax++['\n']




primes :: [Int]
primes = sieve [2..]

sieve :: [Int] -> [Int]
sieve (x:xs) = x:sieve [y| y<-xs, mod y x /= 0]  


