library(Matrix)

vectorize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  vectors <- sapply(words, function(word) {
    sapply(strsplit(word, NULL)[[1]], function(c) {
      as.numeric(charToRaw(c)) * 0.1
    })
  })
  rowMeans(vectors)
}

main <- function() {
  text <- 'Hello world'
  result <- vectorize_text(text)
  print(result)
}

main()