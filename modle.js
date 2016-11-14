var exampleData = {
  name: 'Vue.js'
}
var exampleVM = new Vue({
  el: '#example-1',
  data: exampleData
})
var exampleVM2 = new Vue({
  el: '#example-2',
  data: {
    greeting: false
  }
})
function doSomething()
{
	console.log('doSomething');
	exampleData.name="NOOOOO";
}
var vm = new Vue({
  el: '#example',
  data: {
    a: 1
  },
  computed: {
    // 一个计算属性的 getter
    b: function () {
      // `this` 指向 vm 实例
      return this.a + 1
    }
  }
})
var demo_vm = new Vue({
  el: '#demo',
  data: {
    firstName: 'Foo',
    lastName: 'Bar'
  },
  computed: {
	  fullName: {
	    // getter
	    get: function () {
	      return this.firstName + ' ' + this.lastName
	    },
	    // setter
	    set: function (newValue) {
	      var names = newValue.split(' ')
	      this.firstName = 'z'
	      this.lastName = names[names.length - 1]
	    }
	  },
	 example: {
	 	//cache:false,
    get: function () {
    	var currentdate = new Date(); 
		var datetime = "Last Sync: " + currentdate.getDate() + "/"
                + (currentdate.getMonth()+1)  + "/" 
                + currentdate.getFullYear() + " @ "  
                + currentdate.getHours() + ":"  
                + currentdate.getMinutes() + ":" 
                + currentdate.getSeconds();
                return datetime;
	    }
	  }
  }
})
var class_vm= new Vue({
	el:'.static',
	data: {
	  isA: true,
	  isB: false,
	  ok:false,
	  styleObject: {
	    color: 'red',
	    fontSize: '13px'
	  }
	}
})
/*
var classA_vm = new Vue({
	el:'.static class-a',
	data:{
		styleObject: {
	    color: 'blue',
	    fontSize: '13px'
	  }
	}
})*/
var demo_itemvm=new Vue({
	el:'#demo_item',
	data:
	{
		parentMessage: 'Parent',
		items: [
	      { message: 'Foo' },
	      { message: 'Bar' }
	    ]
	}
})
var z_m=new Vue({
	el:'#z',
	data:
	{
		n:1
	}
})
//to do list
Vue.component('todo-item', {
  template: '\
    <li>\
      {{ title }}\
      <button v-on:click="$emit(\'remove\')">X</button>\
    </li>\
  ',
  props: ['title']
})
new Vue({
  el: '#todo-list-example',
  data: {
    newTodoText: '',
    todos: [
      'Do the dishes',
      'Take out the trash',
      'Mow the lawn'
    ]
  },
  methods: {
    addNewTodo: function () {
      this.todos.push(this.newTodoText)
      this.newTodoText = ''
    }
  }
})

Vue.component('my-component', {
  template: '<div>A custom component!</div>'
})
// create a root instance
var cpvm=new Vue({
  el: '#cpexample'
})
Vue.component('button-counter', {
  template: '<button v-on:click="increment">{{ counter }}</button>',
  data: function () {
    return {
      counter: 0
    }
  },
  methods: {
    increment: function () {
      this.counter += 1
      this.$emit('increment')
    }
  },
})
var btcvm =new Vue({
  el: '#counter-event-example',
  data: {
    total: 0
  },
  methods: {
    incrementTotal: function () {
      this.total += 1
    }
  }
})