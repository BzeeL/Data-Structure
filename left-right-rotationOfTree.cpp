BTree leftRotation(BTree* root){
	new Temp=root->rPtr;
	root->rPtr=Temp->lPtr;
	Temp->lPtr=root;
	return Temp;
}

BTree rightRotating(BTree* root){
	new Temp=root->lPtr;
	root->lPtr=Temp->rPtr;
	Temp->rPtr=root;
	return Temp;
}
