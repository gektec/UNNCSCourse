import Distribution.Simple.Utils (xargs)
data Tree a = Null | Leaf a | Node a (Tree a) (Tree a)

t1 :: Tree Int
t1 = Node 111 (Leaf 777) (Node 333 (Leaf 666) Null)

hasValue :: Tree Int -> Int -> Bool
hasValue Null val = False
hasValue (Leaf l) val = l==val
hasValue (Node n t1 t2) val = n==val || hasValue t1 val || hasValue t2 val


-- [sum [1..x] | x <- [1..10]]

type PersonValue = (String, Int)

db1::[PersonValue]
db1 = [("Mary", 100), ("John", 50), ("Mary", 25), ("Yifan", 75), ("John", 10), ("Mary", 12)]

sumName :: [PersonValue] -> String -> Int
sumName [] _ = -1
sumName ((str, val):xs) name
    | str == name = val
    | otherwise = sumName xs name

hasValueBfs :: Tree Int -> Int -> Bool
hasValueBfs tree val = bfs [tree] val
    where
        bfs [] _ = False
        bfs (Null:xs) val = bfs xs val
        bfs ((Leaf l):xs) val = l == val || bfs xs val
        bfs ((Node n x y):xs) val = n == val || bfs (xs++[x]++[y]) val