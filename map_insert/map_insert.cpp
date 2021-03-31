
// sgi stl _Rb_tree �����㷨 insert_equal() ʵ��.
// ���Ը���: insert_equal() �ں�����ҵ��Լ���λ��,
// Ȼ���� _M_insert() ������������Ĺ���.
// _M_insert() �Ὣ�ڵ����������, ���ŵ��������,
// ά������.
template  < class  _Key, class  _Value, class  _KeyOfValue,
	class  _Compare, class  _Alloc>
	typename  _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
	_Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
	::insert_equal(const  _Value& __v)
{
	// �ں��������ͷ���͸��ڵ�ĸ���, ͷ���λ�ڸ��ڵ�֮��,
	// ͷ���ֻΪ���������, ���ڵ��������洢���ݵĵط�. ͷ���͸��ڵ㻥Ϊ���ڵ�,
	 // ��һ��ʵ�ֵļ���.
	_Link_type __y = _M_header; // ָ��ͷ���
	_Link_type __x = _M_root(); // _M_header->_M_parent, ��ָ����ڵ�

	// Ѱ�Ҳ����λ��
	while (__x != 0) {
		__y = __x;

		// С�ڵ�ǰ�ڵ�Ҫ�����, ���ڵ��ڵ�ǰ�ڵ����ұ�
		__x = _M_key_compare(_KeyOfValue()(__v), _S_key(__x)) ?
			_S_left(__x) : _S_right(__x);
	}
	// __x Ϊ��Ҫ����Ľڵ��λ��, __y Ϊ�丸�ڵ�
	return  _M_insert(__x, __y, __v);
}

// sgi stl _Rb_tree �����㷨 insert_unique() ʵ��.
// ���Ը���: insert_unique() ͬ��Ҳ�ں�������ҵ��Լ���λ��; ����֪��,
// ���С�ڵ��ڵ�ǰ�ڵ��������, ��������һ����ͬ��ֵ�Ľڵ��, ��������һ��,
// ������һֱ������, ���������ʵ�ֻ�������ߵ����������Ĵ���.
template  < class  _Key, class  _Value, class  _KeyOfValue,
	class  _Compare, class  _Alloc>
	pair< typename  _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator,
	bool >
	_Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
	::insert_unique(const  _Value& __v)
{
	_Link_type __y = _M_header; // ָ��ͷ���
	_Link_type __x = _M_root(); // ָ����ڵ�, ����Ϊ��
	bool  __comp = true;

	// Ѱ�Ҳ����λ��
	while (__x != 0) {
		__y = __x;
		__comp = _M_key_compare(_KeyOfValue()(__v), _S_key(__x));

		// С�ڵ�ǰ�ڵ�Ҫ�����, ���ڵ��ڵ�ǰ�ڵ����ұ�
		__x = __comp ? _S_left(__x) : _S_right(__x);
	}

	iterator __j = iterator(__y); // �� __y �Ͻ���������

	// ����Ϊ�����ж������Ƿ��д��ڼ�ֵ������е���,
	// ����������˶���������������, ������� hack, ���������.
	// Ҫ�ر�ע������߲�������.

	// HACKS:
	// ����� if ����Ǳ� __x С����ߵ����: �ᷢ��, �������һ���Ѵ��ڵļ��Ļ�,
	// __y ���ջᶨλ���Ѵ��ڼ�������������������.
	// Ʃ��, ��������Ѿ�����һ����Ϊ 100 �Ľڵ�, ���Һ��ӽڵ�Ϊ 101,
	// ��ʱ����ٲ����Ϊ 100 �Ľڵ�, ��Ϊ 100<=100, ���Ի������ߵ��� 101 �ڵ�,
	// �� 100<101, �̶�������, ��һֱ������.�����΢��һ�����Ӿ������.
	if (__comp)
		// �������, ��� __j ָ����������, ��ô�϶�Ҫ�����½ڵ�.
		if (__j == begin())
			return  pair<iterator, bool >(_M_insert(__x, __y, __v), true);
	// �������, ���ʱ��Ҳ������߲���, ��������ظ��ļ�ֵ,
	// ��ô --__j �ܶ�λ�����ظ��ļ��Ľڵ�.
		else
			--__j;

	// HACKS: ����Ƚϵ��� __j �� __v, ������ڼ�ֵ, ��ô __j == __v,
	// ������ if ���. ����ִ�в���. Ҳ����˵��������ظ��ļ�, ��ô __j
	// ��ֵ�϶��ǵ��� __v
	if (_M_key_compare(_S_key(__j._M_node), _KeyOfValue()(__v)))
		return  pair<iterator, bool >(_M_insert(__x, __y, __v), true);

	// ��ʱ __y.value = __v, ���������, ���ؼ�ֵ����λ��
	return  pair<iterator, bool >(__j, false);
}

// _M_insert() ������ִ�в���ĵط�.
// ���Ը���: ��������Ѿ�����ƪ������, ���Ը�����ƪ���µ�����,
// ����������ע��, ����Ժ���������㷨�����
template  < class  _Key, class  _Value, class  _KeyOfValue,
	class  _Compare, class  _Alloc>
	typename  _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
	_Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
	::_M_insert(_Base_ptr __x_, _Base_ptr __y_, const  _Value & __v)
{
	_Link_type __x = (_Link_type)__x_; // �½ڵ�����λ��.
	// ���� __x ������:
	// 1. �����ŵ������, ��һ�� if �����, �Ҿ�����û�б�Ҫ��,
	// ��Ϊ�ӵ��� _M_insert() �ĺ�������, __x ����Ϊ��.
	// 2. ��Ȼ __x ���½ڵ�����λ��, ��ôΪʲô��ֱ���� __x �ϴ����ڵ�,
	// ��Ҫ������ͨ���Ƚ��������½ڵ������ӻ����Һ���;
	// ����ֱ����ָ���ָ�����ָ������������, ʡȥ��������ж�.

	_Link_type __y = (_Link_type)__y_; // �½ڵ�ĸ��ڵ�
	_Link_type __z; // �½ڵ��λ��

	if (__y == _M_header || __x != 0 ||
		_M_key_compare(_KeyOfValue()(__v), _S_key(__y))) {
		// �½ڵ�Ӧ��Ϊ����
		__z = _M_create_node(__v);
		_S_left(__y) = __z;               // also makes _M_leftmost() = __z
										  //    when __y == _M_header
		if (__y == _M_header) {
			_M_root() = __z;
			_M_rightmost() = __z;
		}
		else  if (__y == _M_leftmost())
			_M_leftmost() = __z;   // maintain _M_leftmost() pointing to min node
	}
	// �½ڵ�Ӧ��Ϊ�Һ���
	else {
		__z = _M_create_node(__v);
		_S_right(__y) = __z;
		if (__y == _M_rightmost())
			_M_rightmost() = __z;  // maintain _M_rightmost() pointing to max node
	}
	_S_parent(__z) = __y;
	_S_left(__z) = 0;
	_S_right(__z) = 0;

	// ���µ���
	_Rb_tree_rebalance(__z, _M_header->_M_parent);

	// ���º�����ڵ���
	++_M_node_count;

	// ���ص���������
	return  iterator(__z);
}

// �����½ڵ��, ���ܻ��ƻ����������, _Rb_tree_rebalance() ����ά������.
// ����:
// __x �²���Ľڵ�
// __root ���ڵ�
// ���Ը���: ������������µ����Ĳ����Ѿ�����ƪ�н���,
// ���Խ����ƪ���º�����Ĵ���ע��,
// ��������Ĳ����㷨.
inline  void
_Rb_tree_rebalance(_Rb_tree_node_base * __x, _Rb_tree_node_base * &__root)
{
	// ���²���Ľڵ�Ⱦ�ɺ�ɫ
	__x->_M_color = _S_rb_tree_red;

	while (__x != __root && __x->_M_parent->_M_color == _S_rb_tree_red) {
		// __x �ĸ��ڵ�Ҳ�Ǻ�ɫ�����. ��ʾ: ����Ǻ�ɫ�ڵ�, �����ƻ����������.

		if (__x->_M_parent == __x->_M_parent->_M_parent->_M_left) {
			// �常�ڵ�
			_Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_right;

			if (__y && __y->_M_color == _S_rb_tree_red) {
				// �� 1 �����, N,P,U ����(G �϶���).
				// ����: G->��, N,P->��. ��ʱ, G ��, ��� G �ĸ���Ҳ�Ǻ�, �����ֱ��ƻ���,
				// HACK: ���Խ� GPUN ����һ���µĺ�ɫ N �ڵ�, ��˵ݹ������ȥ;
				// ���׵�, ������ɽ����ڵ�Ⱦ���˺�ɫ, �������㷨�����ǿ�� root->��.
				__x->_M_parent->_M_color = _S_rb_tree_black;
				__y->_M_color = _S_rb_tree_black;
				__x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
				__x = __x->_M_parent->_M_parent;
			}
			else {

				if (__x == __x->_M_parent->_M_right) {
					// �� 2 �����, P Ϊ��, N Ϊ P �Һ���, U Ϊ�ڻ�ȱ��.
					// ����: ��ת�任, �Ӷ�������һ�����:
					__x = __x->_M_parent;
					_Rb_tree_rotate_left(__x, __root);
				}
				// �� 3 �����, �����ɵڶ��ֱ仯����, ������һ��: P Ϊ��, N Ϊ��.
				// ����: ��ת, ���� P,G ��ɫ, ������, ��Ϊ P Ϊ��ɫ, ���Բ���
				// P �ĸ��ڵ��Ǻ�ɫ�����. over
				__x->_M_parent->_M_color = _S_rb_tree_black;
				__x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
				_Rb_tree_rotate_right(__x->_M_parent->_M_parent, __root);
			}
		}
		else { // ����Ĵ����Ǿ���ó���, �Բ���.
			_Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_left;
			if (__y && __y->_M_color == _S_rb_tree_red) {
				__x->_M_parent->_M_color = _S_rb_tree_black;
				__y->_M_color = _S_rb_tree_black;
				__x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
				__x = __x->_M_parent->_M_parent;
			}
			else {
				if (__x == __x->_M_parent->_M_left) {
					__x = __x->_M_parent;
					_Rb_tree_rotate_right(__x, __root);
				}
				__x->_M_parent->_M_color = _S_rb_tree_black;
				__x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
				_Rb_tree_rotate_left(__x->_M_parent->_M_parent, __root);
			}
		}
	}
	__root->_M_color = _S_rb_tree_black;
}

// ɾ���㷨, ֱ�ӵ��õײ��ɾ��ʵ�� _Rb_tree_rebalance_for_erase().
template  < class  _Key, class  _Value, class  _KeyOfValue,
	class  _Compare, class  _Alloc>
	inline  void  _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
	::erase(iterator __position)
{
	_Link_type __y =
		(_Link_type)_Rb_tree_rebalance_for_erase(__position._M_node,
			_M_header->_M_parent,
			_M_header->_M_left,
			_M_header->_M_right);
	destroy_node(__y);
	--_M_node_count;
}

// ɾ���ڵ�ײ�ʵ��, ɾ�����ܻ��ƻ����������,
// _Rb_tree_rebalance()
// ����ά������. ����:
// __z ��Ҫɾ���Ľڵ�
// __root ���ڵ�
// __leftmost ������ڲ�����, ����������
// __rightmost ������ڲ�����, ����������
// ���Ը���: _Rb_tree_rebalance_for_erase() �����
// ɾ���ڵ��λ���ں�������ҵ�����ɾ���ڵ�Ľڵ�,
// ���޷���ɾ���ڵ������������ڵ���������е���С�ڵ�,
// �˴��õ�����һ�ֲ���. ����, ������������ά������.
// �������㷨�Ѿ�����ƪ����������, ���Ը�����ƪ���µ�����
// �ʹ�ƪ�Ĵ���ע��, ����Ժ����ɾ���㷨�����.
inline  _Rb_tree_node_base*
_Rb_tree_rebalance_for_erase(_Rb_tree_node_base * __z,
	_Rb_tree_node_base * &__root,
	_Rb_tree_node_base * &__leftmost,
	_Rb_tree_node_base * &__rightmost)
{
	// __z ��Ҫɾ���Ľڵ�

	// __y ���ջ�ָ��Ҫɾ���Ľڵ�
	_Rb_tree_node_base* __y = __z;
	// N �ڵ�
	_Rb_tree_node_base* __x = 0;
	// ��¼ N �ڵ�ĸ��ڵ�
	_Rb_tree_node_base* __x_parent = 0;

	// ֻ��һ�����ӻ���û�к��ӵ����
	if (__y->_M_left == 0)     // __z has at most one non-null child. y == z.
		__x = __y->_M_right;     // __x might be null.
	else
		if (__y->_M_right == 0)  // __z has exactly one non-null child. y == z.
			__x = __y->_M_left;    // __x is not null.

		  // �������ǿպ���
		else {                   // __z has two non-null children.  Set __y to
			__y = __y->_M_right;   //   __z's successor.  __x might be null.

			// __y ȡ�Һ����е���С�ڵ�, __x ��¼�����Һ���(���ܴ����Һ���)
			while (__y->_M_left != 0)
				__y = __y->_M_left;
			__x = __y->_M_right;
		}

	// __y != __z ˵���������ǿպ��ӵ����,
	// ��ʱ��ɾ�����Ծͺ������ᵽ����ͨ����������ɾ������һ��:
	// __y ��¼�� __z ����������С�Ľڵ�
	// __x ��¼�� __y ���Һ���
	// �� __y ���� __z ��λ��, __x ���� __y ��λ��, ����� __y ָ�� __z,
	// �Ӷ� __y ָ����Ҫɾ���Ľڵ�
	if (__y != __z) {          // relink y in place of z.  y is z's successor

	  // �� __z �ļ�¼ת���� __y �ڵ�
		__z->_M_left->_M_parent = __y;
		__y->_M_left = __z->_M_left;

		// ��� __y ���� __z ���Һ���, __z->_M_right ������
		if (__y != __z->_M_right) {

			__x_parent = __y->_M_parent;

			// ��� __y ���Һ��� __x, �������Ǹ� __x �滻 __y ��λ��
			if (__x)
				// �滻 __y ��λ��
				__x->_M_parent = __y->_M_parent;

			__y->_M_parent->_M_left = __x;      // __y must be a child of _M_left
			__y->_M_right = __z->_M_right;
			__z->_M_right->_M_parent = __y;
		}
		// __y == __z->_M_right
		else
			__x_parent = __y;

		// ��� __z �Ǹ��ڵ�
		if (__root == __z)
			__root = __y;

		// __z ������
		else  if (__z->_M_parent->_M_left == __z)
			__z->_M_parent->_M_left = __y;

		// __z ���Һ���
		else
			__z->_M_parent->_M_right = __y;

		__y->_M_parent = __z->_M_parent;
		// ������Ҫɾ���ڵ� __z �� �滻�ڵ� __y ����ɫ
		__STD::swap(__y->_M_color, __z->_M_color);
		__y = __z;
		// __y now points to node to be actually deleted
	}
	// __y != __z ˵������һ������
	else {                        // __y == __z
		__x_parent = __y->_M_parent;
		if (__x) __x->_M_parent = __y->_M_parent;

		// �� __z �ĸ���ָ�� __x
		if (__root == __z)
			__root = __x;
		else
			if (__z->_M_parent->_M_left == __z)
				__z->_M_parent->_M_left = __x;
			else
				__z->_M_parent->_M_right = __x;

		// __leftmost �� __rightmost �Ǻ�������ڲ�����, ��Ϊ __z ������
		// __leftmost ���� __rightmost, �����Ҫ����.
		if (__leftmost == __z)
			if (__z->_M_right == 0)        // __z->_M_left must be null also
			  // __z ���Һ��Ӷ�Ϊ��, û�к���
				__leftmost = __z->_M_parent;
		// makes __leftmost == _M_header if __z == __root
			else
				__leftmost = _Rb_tree_node_base::_S_minimum(__x);

		if (__rightmost == __z)
			if (__z->_M_left == 0)         // __z->_M_right must be null also
				__rightmost = __z->_M_parent;
		// makes __rightmost == _M_header if __z == __root
			else                       // __x == __z->_M_left
				__rightmost = _Rb_tree_node_base::_S_maximum(__x);

		// __y ͬ���Ѿ�ָ��Ҫɾ���Ľڵ�
	}

	// __y ָ��Ҫɾ���Ľڵ�
	// __x ��Ϊ N �ڵ�
	// __x_parent ָ�� __x �ĸ���, �� N �ڵ�ĸ���
	if (__y->_M_color != _S_rb_tree_red) {
		// __y ����ɫΪ��ɫ��ʱ��, ���ƻ����������

		while (__x != __root && (__x == 0 || __x->_M_color == _S_rb_tree_black))
			// __x ��Ϊ��ɫ, ��Ϊ�ջ���Ϊ��. ��ʾ: ��� __x �Ǻ�ɫ, ֱ�ӽ� __x �滻�ɺ�ɫ

			if (__x == __x_parent->_M_left) { // ��� __x ������

				_Rb_tree_node_base* __w = __x_parent->_M_right; // �ֵܽڵ�

				if (__w->_M_color == _S_rb_tree_red) {
					//�� 2 ���, S ��, ���ݺ��������P,SL,SR һ����.
					// ����: ��ת, ���� P,S ��ɫ.

					__w->_M_color = _S_rb_tree_black;
					__x_parent->_M_color = _S_rb_tree_red; // ������ɫ
					_Rb_tree_rotate_left(__x_parent, __root); // ��ת
					__w = __x_parent->_M_right; // ������ϵ
				}

				if ((__w->_M_left == 0 ||
					__w->_M_left->_M_color == _S_rb_tree_black) &&
					(__w->_M_right == 0 ||
						__w->_M_right->_M_color == _S_rb_tree_black)) {
					// ��ʾ: ���� �� 1 ����͵� 2.1 ����ĺϲ�, ��Ϊ����Ĺ�����һ����.
					// �����ǵ��������Ҫ���ű����. �Ѿ�����������ϸ֧��,
					// �ƺ�������Ĳ�����û���ᵽ��һ��.

					// �� 1 ���, N,P,S,SR,SL ����.
					// ����: S->��. ͨ�� PN,PS �ĺ�ɫ�ڵ�������ͬ��, ���������·����һ��,
					// ����ķ������� P �ϴ���� 0 ��ʼ��������.
					// ΪʲôҪ������? HACKS: ��Ϊ��Ȼ PN,PS
					// ·���ϵĺڽڵ�������ͬ���ұ�����·������һ���ڽڵ�,
					// �Ǻβ��������忴����һ�� N �ڵ�! ���ǵݹ�ԭ��.

					// �� 2.1 ���, S,SL,SR ����.
					// ����: P->��. S->��, ��Ϊͨ�� N ��·������һ���ڽڵ�,
					// ͨ�� S �ĺڽڵ��������, ����ά�������� 5. over

					// ���ܴ�һ�������, ���԰�, 2.1 �����,
					// �����ǽ������ڵ���ֵܽڵ����ɫ, ��ʱ��ôû�жԸ��ڵ����ɫ��ֵ��?
					// HACKS: ����Ǻϲ�����ĺô�, ��Ϊ�����ʱ���ڵ��Ǻ�ɫ,
					// ����Ҳ���ֵܽڵ���ɫ��Ϊ��ɫ, ��Ҳ���Խ� PS,PN ����һ����ɫ�� N �ڵ�,
					// ��������һ��ѭ������, ��� N �ڵ�Ҳ���ɺ�ɫ. ��Ϊ�˺��������һ�仰:
					// if (__x) __x->_M_color = _S_rb_tree_black;
					// �ϲ����, ��ʡ������

					// ��Ȼ�ǿ��Էֿ�д��

					// �ֵܽڵ�Ⱦ�ɺ�ɫ
					__w->_M_color = _S_rb_tree_red;

					// ������ϵ
					__x = __x_parent;
					__x_parent = __x_parent->_M_parent;
				}
				else {
					if (__w->_M_right == 0 ||
						__w->_M_right->_M_color == _S_rb_tree_black) {
						// �� 2.2.1 ���, S,SR ��, SL ��.
						// ����: ��ת, �任 SL,S ��ɫ.

						if (__w->_M_left) __w->_M_left->_M_color = _S_rb_tree_black;
						__w->_M_color = _S_rb_tree_red;
						_Rb_tree_rotate_right(__w, __root);

						// ������ϵ
						__w = __x_parent->_M_right;
					}

					// �� 2.2.2 ���, S ��, SR ��.
					// ����: ��ת, ���� S,P ��ɫ, SR->��ɫ, ���»��ƽ��.
					__w->_M_color = __x_parent->_M_color;
					__x_parent->_M_color = _S_rb_tree_black;
					if (__w->_M_right) __w->_M_right->_M_color = _S_rb_tree_black;
					_Rb_tree_rotate_left(__x_parent, __root);
					break;
				}                        // ����Ĵ����Ǿ���ó���, �Բ���.
			}
			else {                  // same as above, with _M_right <-> _M_left.
				_Rb_tree_node_base* __w = __x_parent->_M_left;
				if (__w->_M_color == _S_rb_tree_red) {
					__w->_M_color = _S_rb_tree_black;
					__x_parent->_M_color = _S_rb_tree_red;
					_Rb_tree_rotate_right(__x_parent, __root);
					__w = __x_parent->_M_left;
				}
				if ((__w->_M_right == 0 ||
					__w->_M_right->_M_color == _S_rb_tree_black) &&
					(__w->_M_left == 0 ||
						__w->_M_left->_M_color == _S_rb_tree_black)) {
					__w->_M_color = _S_rb_tree_red;
					__x = __x_parent;
					__x_parent = __x_parent->_M_parent;
				}
				else {
					if (__w->_M_left == 0 ||
						__w->_M_left->_M_color == _S_rb_tree_black) {
						if (__w->_M_right) __w->_M_right->_M_color = _S_rb_tree_black;
						__w->_M_color = _S_rb_tree_red;
						_Rb_tree_rotate_left(__w, __root);
						__w = __x_parent->_M_left;
					}
					__w->_M_color = __x_parent->_M_color;
					__x_parent->_M_color = _S_rb_tree_black;
					if (__w->_M_left) __w->_M_left->_M_color = _S_rb_tree_black;
					_Rb_tree_rotate_right(__x_parent, __root);
					break;
				}
			}
		if (__x) __x->_M_color = _S_rb_tree_black;
	}
	return  __y;
}
