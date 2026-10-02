library(tm)
library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
    fields = list(
        corpus = "character",
        tokenized = "list",
        vocabulary = "list",
        vectorized = "dgCMatrix"
    ),
    methods = list(
        initialize = function(corpus) {
            .self$corpus <- corpus
            .self$tokenized <- .self$tokenize()
            .self$vocabulary <- .self$build_vocabulary()
            .self$vectorized <- .self$vectorize()
        },
        tokenize = function() {
            return(lapply(.self$corpus, function(doc) {
                strsplit(tolower(doc), " ")[[1]]
            }))
        },
        build_vocabulary = function() {
            vocab <- unique(unlist(.self$tokenized))
            return(sapply(vocab, function(word) which(vocab == word)))
        },
        vectorize = function() {
            vectors <- lapply(.self$tokenized, function(doc) {
                vector <- sparseVector(x = rep(1, length(doc)), i = .self$vocabulary[doc], length = length(.self$vocabulary))
                return(vector)
            })
            return(sparseMatrix(d = unlist(vectors), i = rep(1:length(vectors), sapply(vectors, length)), j = unlist(lapply(vectors, function(v) which(v != 0)))))
        }
    )
)

load_data <- function() {
    return(c('This is a sample document', 'Another document for testing', 'Sample document number three'))
}

analyze_vectors <- function(vectors) {
    average_vector <- rowMeans(vectors)
    max_vector <- apply(vectors, 1, max)
    return(list(average_vector, max_vector))
}

main <- function() {
    data <- load_data()
    vectorizer <- Vectorizer$new(data)
    average <- analyze_vectors(vectorizer$vectorized)[[1]]
    maximum <- analyze_vectors(vectorizer$vectorized)[[2]]
    print(paste('Average Vector:', average))
    print(paste('Maximum Vector:', maximum))
}

main()