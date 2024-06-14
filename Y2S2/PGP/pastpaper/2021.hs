applyToLists :: [a] -> [b] -> (a -> b -> c) -> [c]
applyToLists [] _ _ = []
applyToLists _ [] _ = []
applyToLists (x:xs) (y:ys) f = f x y:applyToLists xs ys f

getValues :: [(Int, String)] -> Int -> [String]
getValues [] _ = []
getValues ((id, val):xs) key
    | id == key = val:getValues xs key
    | otherwise = getValues xs key

store1 :: [(Int, String)]
store1 = [ (2, "red"), (3, "green"), (2, "blue"), (1, "black") ]

data Tree a = Leaf a | Node (Tree a) a (Tree a)

t :: Tree Int
t = Node (Node (Leaf 1) 3 (Leaf 4)) 5 (Node (Leaf 6) 7 (Leaf 9))

onLeaf :: Eq a => Tree a -> a -> Bool
onLeaf (Leaf l) val = l==val
onLeaf (Node x l y) val = onLeaf x val || onLeaf y val

foldt :: (b->b->b) -> (a->b) -> Tree a -> b
foldt _ g (Leaf x) = g x
foldt f g (Node t1 x t2) = f (f (g x) (foldt f g t1)) (foldt f g t2)

occurs x = foldt (||) (==x)

sumTree :: Tree Int -> Int
sumTree tree = foldt (+) (\x->x) tree
