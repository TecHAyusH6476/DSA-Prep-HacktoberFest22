class Solution {
    String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                    "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    public String numberToWords(int num) {
        if (num == 0)
            return "Zero";
        
        return helper(num).trim();
    }
    
    private String helper(int num) {
        StringBuilder sb=new StringBuilder();
        if (num >= 1000000000) {
            sb.append(helper(num / 1000000000)).append(" Billion ").append( helper(num % 1000000000));
        } else if  (num >= 1000000) {
            sb.append(helper(num / 1000000)).append(" Million ").append( helper(num % 1000000));
        }else if (num >= 1000) {
            sb.append(helper(num / 1000)).append(" Thousand ").append( helper(num % 1000));
        }else if (num >= 100) {
            sb.append(helper(num / 100)).append(" Hundred ").append( helper(num % 100));
        }else if (num >= 20) {
            sb.append(tens[num / 10]).append(" ").append( helper(num % 10));
        } else {
            sb.append(ones[num]);
        }
        return sb.toString().trim();
        
    }
}
