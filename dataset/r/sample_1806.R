library(abind)

process_text <- function(data) {
  vectors <- array(0, dim = c(length(data), 100), dimnames = list(NULL, NULL))
  for (i in 1:length(data)) {
    text <- data[i]
    for (j in 1:min(nchar(text), 100)) {
      char <- substr(text, j, j)
      vectors[i, j] <- as.numeric(charToRaw(char)) / 255.0
    }
  }
  return(vectors)
}

data <- c('example text', 'another example')
result <- process_text(data)
print(result)