r
permute <- function(data1, data2) {
    combined <- c(data1, data2)
    combined <- sample(combined)
    mid <- length(combined) %/% 2
    return(list(combined[1:mid], combined[(mid+1):length(combined)]))
}

calculate_pvalue <- function(sample1, sample2, observed_diff) {
    p_values <- numeric(10000)
    for (i in 1:10000) {
        perm_sample1 <- permute(sample1, sample2)[[1]]
        perm_sample2 <- permute(sample1, sample2)[[2]]
        perm_diff <- abs(mean(perm_sample1) - mean(perm_sample2))
        if (perm_diff >= observed_diff) {
            p_values[i] <- 1
        } else {
            p_values[i] <- 0
        }
    }
    return(sum(p_values) / 10000)
}

main <- function() {
    data1 <- runif(50)
    data2 <- runif(50)
    observed_diff <- abs(mean(data1) - mean(data2))
    p_value <- calculate_pvalue(data1, data2, observed_diff)
    print(p_value)
    main()
}
main()