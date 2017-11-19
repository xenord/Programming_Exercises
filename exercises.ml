(*  
	#use "exercises.ml";;
*)



(*
let rec fact (n : int) : int = match n with
								|0 -> 1
								|1 -> 1
								|n when n > 1 -> (n*fact(n-1))
								|_ -> failwith ("Questo non dovrebbe succedere!");;


let rec exp (n : int) (m : int) : int = if m = 0 then 1
										else n*(exp n (m-1));;


let rec sumbetween (n : int) (m : int) : int = if (n > m) then 0
												else if (n = m) then n
												else n + (sumbetween(n+1) m);;
*)


(* NUMERI PERFETTI *)

(*
let rec aux (n : int) (m : int) : int = if m = n then m
										else if n mod m = 0 then m + aux n (m+1)
										else aux n (m+1);;


let perfetto (n : int) : bool = if (aux n 1) = (2*n)
									then true
								else false;;
*)


(* MCD EUCLIDEO *)
(*
let rec gcd (x : int) (y : int) : int = match (x,y) with
											|x,y when y = 0 -> x
											|x,y when x mod y = 0 -> y
											|x,y -> gcd y (x mod y);;
*)

(* numeri coprimi *)
(*
let rec aux x y n = match x mod n, y mod n with
							| 0, 0 -> false
							| _, _ when n > (min x y) -> true
							| _, _ -> aux x y (n + 1);;		

let rec coprime (x : int) (y : int) : bool = aux x y 2;;
*)


(* interi da n a m *)

(*
let rec interidaa (n : int) (m : int): int list = if n > m then []
													else n::(interidaa (n+1) m);;
*)


(* primi n elementi di una lista *)
(*
let rec primielementi (n : int) (lst : int list) : int list = match (n, lst) with
																|(n, _ ) when n = 0 -> []
																|(_, []) -> []
																|(_, x::lst) -> x::(primielementi(n-1) lst);;
*)


(* mix, unire due liste alternando gli elementi *)
(*
let rec mix (lst1 : 'a list) (lst2 : 'a list) : 'a list = match (lst1, lst2) with
																|([], []) -> []
																|(x::xs, []) -> x::xs
																|([], y::ys) -> y::ys
																|(x::xs, y::ys) -> x::y::(mix (xs) ys);;
*)


(* data una lista dire se è ordinata *)
(*
type risultato = Ordinato | NonOrdinato;;
	
let rec is_order (lst : 'a list) : risultato = match lst with
											|[] -> Ordinato
											|[x] -> Ordinato
											|x::y::xs when x > y -> NonOrdinato
											|x::y::xs when x < y -> is_order(y::xs);;
*)


(* tab k n, restituire i primi n numeri della tabellina del k *)
(*
let rec aux (k : int) (n : int) (i : int) : int list = match (k, n, i) with
															|(0, _, _) -> []
															|(_, 0, _) -> []
															|(_, _, 0) -> []
															|(k, n, i) -> (k*i) :: (aux k (n-1) (i+1));;


let rec tab (k : int) (n : int) : int list = aux k n 1;;
*)

(* Numeri belli, se solo se la sua ultima cifra è 0,3,7 e la penultima non lo è *)

(*
let rec aux (m: int): int list = match m with
									|m when m mod 10 = 0 -> []
									|m when m mod 10 <> 0 -> m mod 10 :: (aux (m/10));;

let rec check_beauty (lst : int list) (len : int): bool = match (lst, len) with
															|(x::xs, 0) when x <> 0 & x <> 3 & x <> 7 -> true
															|(x::xs, 0) when (x = 0) or (x = 3) or (x = 7) -> false
															|(x::xs, 1) when x <> 0 & x <> 3 & x <> 7 -> false
															|(x::xs, 1) when x = 0 or x = 3 or x = 7 -> (check_beauty xs (len-1));;


let aux2 (n : int) : bool = match n with
									|n when n = 0 or n = 3 or n = 7 -> true
									|n when n <> 0 && n <> 3 && n <> 7 -> false;;

let bello (n : int ) : bool = if n < 10 then (aux2 n)
								else (check_beauty (aux n) b1);;
*)



(* Data una lista di coppie contenenti (nome corso, numero crediti) e dato il nome del corso ricavare il numero crediti se il corso esiste altrimenti restituire 0  *)
(*
let piano_di_studi = [("programmazione", 12); ("architettura", 12); ("matematica", 6); ("algebra", 6)];;


let rec analizza (str : string) (lst : (string * int) list) : int = match (str, lst) with
																	|(str, (x,y)::xs) when x = str -> y
																	|(str, []) -> 0
																	|(str, (x,y)::xs) -> (analizza str (xs));;

let main (str : string) : int = (analizza str piano_di_studi);;
*)


(* Data una lista di coppie contenenti (nome corso, numero crediti) e un altra lista contenente coppie (nome corso, voto) calcolare la media dei voti *)

(*
let libretto1 = [("programmazione", 22); ("architettura", 26); ("matematica", 24)];;

let piano_di_studi = [("programmazione", 12); ("architettura", 12); ("matematica", 6); ("algebra", 6)];;


let rec media_dei_voti_aux (lst1 : (string * int) list) (lst2 : (string * int) list)  : (int * int) list = match ((lst1), (lst2)) with
																												|([], (m,n)::ms) -> [(0, 0)]
																												|((x,y)::xs, (m,n)::ms) when x = m -> (y,n) :: (media_dei_voti_aux xs (ms))
																												|((x,y)::xs, (m,n)::ms) when x <> m -> (media_dei_voti_aux xs (ms));;


let rec media_dei_voti (lst : (int * int) list) : int = match lst with
															|[] -> 0
															|((x,y)::xs) -> x + (media_dei_voti xs);;

let rec crediti (lst : (int * int) list) : int = match lst with
															|[] -> 0
															|((x,y)::xs) -> y + (crediti xs);;

let rec lenlst (lst : (int * int) list) : int = match lst with 
													|[] -> 0
													|x::xs -> 1 + lenlst(xs);;

let main (lst : (string * int) list) : float * int = ((float_of_int(media_dei_voti (media_dei_voti_aux libretto1 piano_di_studi))/.float_of_int(3)), (crediti (media_dei_voti_aux libretto1 piano_di_studi)));;


*)

(* Implementazione del merge sort *)
(*
let rec lenlst (lst : int list) : int = match lst with
										|[] -> 0
										|[x] -> 1
										|x::xs -> 1 + (lenlst xs);;

let rec first_n_element (lst : int list) (len : int) : int list = match lst with
																	|[] -> []
																	|[x] -> [x] 
																	|(x::xs) when len = 0 -> []
																	|(x::xs) -> x::(first_n_element (xs) (len-1));;

let rec last_n_element (lst : int list) (len : int) : int list = match lst with
																	|[] -> []
																	|[x] -> [x] 
																	|(x::xs) when len > len/2 -> (last_n_element xs (len-1))
																	|(x::xs) -> x::(last_n_element (xs) (len-1));;


let main (lst : int list) : int list = (last_n_element lst (lenlst lst));;
*)												

(* inverso di una lista usando ricorsione in coda *)
(*
let rec inverti l = 
		match l with
		|[]->[]
		|x::xs->inverti xs @[x];;
*)

(* inserimento in cosa *)
(*
let rec int_to_list (n:int):int list = match n with
										|n when n/10=0->[n]
										|n when n/10 > 0-> int_to_list (n/10)@[n mod 10]
										|_->failwith "errore";;
*)

(* rimozione duplicati da una lista *)
(*
let rec compress (lst : string list) : string list = match lst with
														|[] -> []
														|[x] -> [x]
														|(x::(y::xs)) when x<>y -> x::(compress xs)
														|(x::(y::xs)) when x=y -> (compress xs);;
*)

(* funziona che verifica che se una lista dei libri è contenuta TUTTA nello scaffale *)

let scaffale = [("odissea", 1200); ("eneide", 8465); ("divina commedia", 7498); ("amleto", 9867)];;

let lista_libri_1 = ["odissea"; "divina commedia"; "amleto"];;

let lista_libri_2 = ["odissea"; "edipo re";"eneide"; "amleto"];;

let rec cerca (str : string) (l2 : (string * int)list) : bool = match (str, l2) with
																	|(_, []) -> false
																	|(str, (x,y)::tl) -> if str=x then true else (cerca str tl);;


let rec verifica (l1 : string list) (l2 : (string*int)list) : bool = match (l1, l2) with
																		|([], _) -> true
																		|(_, []) -> false
																		|((hd::tl),((x,y)::xs)) -> if (cerca hd l2) = false then false else (verifica tl l2);;

let main = (verifica lista_libri_1 scaffale);;
