library(tm)
library(slam)

vectorize_texts <- function(texts) {
  corpus <- Corpus(VectorSource(texts))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = FALSE)))
  return(as.matrix(dtm))
}

main <- function() {
  texts <- c('hello world', 'goodbye world', 'hello everyone')
  vectors <- vectorize_texts(texts)
  print(vectors)
}

main()