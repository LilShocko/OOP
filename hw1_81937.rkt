#lang racket
(define (square x) (* x x))

(define (count-digits n)
  (if (= n 0) 0 (+ 1 (count-digits (quotient n 10)))))

(define (automorphic2 squaredn n)
   (cond
   [(= squaredn n) #t]
   [(= squaredn 0) #f]
   [else (automorphic2 (remainder squaredn (expt 10 (- (count-digits squaredn) 1))) n)]))

(define (automorphic? n)
  (automorphic2 (square n) n))




(define (cube n) (* n n n))

(define (divisible? n k) (= (remainder n k) 0))

(define (prime? n)
  (define max-prime-factor-n (floor (sqrt n)))
  (define (prime-helper? i)
    (cond
     [(> i max-prime-factor-n) #t]
     [(divisible? n i) #f]
     [else (prime-helper? (+ i 1))]))
  (and (> n 1) (prime-helper? 2)))


(define (two a b) (- (cube a) (cube b)))


(define (nth-cuban n)
  (define (cuban-iter a b n counter number)
    (cond
      [(= n counter) number]
      [(prime? (two a b)) (cuban-iter (+ a 1) (+ b 1) n (+ counter 1) (two a b)) ]
      [else (cuban-iter (+ a 1) (+ b 1) n counter number)]))
 (cuban-iter 2 1 (+ n 1) 1 0))
  




  


