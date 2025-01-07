nt getMaxWidth(Node* root) {

        // Your code here
        if(root==NULL)return 0;
        queue<Node*>q;
        q.push(root);
        int maxi=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; i++){
                Node*node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            maxi=max(maxi,s);
        }
        return maxi;
    }

