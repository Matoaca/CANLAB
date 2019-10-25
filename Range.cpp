Range Range::Split(){
	Range q = inverse();
	Range rv;
	if(top.distance(q.top) == top.distance(q.bottom)) (0.00001){
		rv.top = (top + q.top)/2;
		rv.bottom = bottom;
		bottom = (bottom + q.bottom)/2;
	}else{
		rv.top = (top + q.top)/2;
		rv.bottom = bottom;
		bottom = (bottom + q.top)/2;
	}
	return rv;
}

bool Range::borders(Range r){
	Range q = r.inverse();
	int count = 0;
	count += inside(r.top) ?1:0;
	count += inside(r.bottom) ?1:0;
	count += inside(q.top) ?1:0;
	count += inside(q.bottom) ?1:0;
	
	return count == 2;
}

Range Range::inverse(){
	Range rv;
	rv.top = Point(top.y, bottom.x);
	rv.bottom = Point(top.x, bottom.y);
	return rv;
}
