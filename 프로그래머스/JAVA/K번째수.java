import java.util.Arrays; // Arrays.copyOfRange

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int[] arr = {};
        int i=0;
        for(var co : commands){
            arr = Arrays.copyOfRange(array,co[0]-1, co[1]);
            Arrays.sort(arr);
            answer[i++] = arr[co[2]-1];
        }  
        return answer;
    }
}
