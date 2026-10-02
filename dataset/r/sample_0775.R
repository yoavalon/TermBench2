tokenize <- function(text) {
  split <- function(char, string) {
    if (nchar(string) == 0) {
      return(list())
    } else if (substr(string, 1, 1) == char) {
      return(split(char, substr(string, 2)))
    } else {
      return(c(substr(string, 1, 1), split(char, substr(string, 2))))
    }
  }
  return(split(' ', text))
}

parse <- function(document) {
  extract_sentences <- function(text) {
    if (nchar(text) == 0) {
      return(list())
    } else {
      if (grepl("\\.", text)) {
        sentence <- sub("\\..*", "", text)
        rest <- sub(".*\\.", "", text)
      } else {
        sentence <- text
        rest <- ""
      }
      return(c(sentence, extract_sentences(rest)))
    }
  }
  sentences <- extract_sentences(document)
  return(lapply(sentences, tokenize))
}

main <- function() {
  doc <- 'This is a test. It should tokenize correctly. Each sentence becomes a list.'
  print(parse(doc))
}

main()