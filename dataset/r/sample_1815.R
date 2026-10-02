library(Matrix)

vectorize_text <- function(texts, dim = 100) {
    vectors <- matrix(runif(length(texts) * dim), nrow = length(texts), ncol = dim)
    return(vectors)
}

if (isTRUE(interactive())) {
    texts <- c('Hello world', 'Python programming', 'Natural language processing')
    vectors <- vectorize_text(texts)
    print(vectors)
}